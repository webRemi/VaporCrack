/*|-----------------------|*/
/*|> VaporCrack.c ~ 4$X  <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#define SIZE 100
#define MD5_SIZE 16
#define SHA1_SIZE 20
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

char *convert_to_md5(char *word); // convert word to md5
char *convert_to_sha1(char *word); // convert word to sha1
char *extract_file(char *fitem); // extract iitem from file
int verify_string(char *result, char *hash); // compare converted word with hash
void status_cracked(int ans, char *word); // display cracked status
void status_no_cracked(); // display no-cracked status
void help_menu(char *help); // display help menu
void red(); // set red color
void bold(); // set bold 
void reset(); // reset display effects

int main(int argc, char *argv[]) {
    printf(
    "  _                                                              \n"
    "- - _-                            ,- _~.                  ,,   \n"
    "  )-  )   _                      (' /|           _        ||   \n"
    "  )___)  < \\, -_-_   /'\\\\ ,._-_ ((  ||   ,._-_  < \\,  _-_ ||/\\ \n"
    " ~)___)  /-|| || \\\\ || ||  ||   ((  ||    ||    /-|| ||   ||_< \n"
    "  )  )  (( || || || || ||  ||    ( / |    ||   (( || ||   || | \n"
    " /-_/    \\/\\\\ ||-'  \\\\,/   \\\\,    -____-  \\\\,   \\/\\\\ \\\\,/ \\\\,\\\n"
    "              |/                                                 \n"
    "              '                                                 \n"
    "                      	                                     \n"
    );
    printf("|> Starting program...\n");
    char *name = argv[0];
    char *arg = argv[1];
	char *arg2 = argv[2];
	char *algo = argv[3];
    char *fhash = argv[4];
    char *fword = argv[5];
    if (argc == 6 && strcmp(arg, "-d") == 0) {
		if (strcmp(arg2, "-a") == 0) {
			if (strcmp(algo, "md5") == 0) {
				printf("|> Enter md5 mode...\n");
			} else if (strcmp(algo, "sha1") == 0) {
				printf("|> Enter sha1 mode...\n");
			}
		}
		char *hash = extract_file(fhash);
		FILE *fopen(), *fp;
		char word[SIZE];
		if ((fp = fopen(fword, "r")) == NULL) {
			fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		}
		printf("|\n");
		printf("|> Cracking...\n");
		while (!feof(fp)) {
			fgets(word, SIZE, fp);
			word[strcspn(word, "\n")] = '\0';
			if (strcmp(algo, "md5") == 0) {
				char *result = convert_to_md5(word);
				int ans = verify_string(result, hash);
				status_cracked(ans, word);
			} else if (strcmp(algo, "sha1") == 0) {
				char *result = convert_to_sha1(word);
				int ans = verify_string(result, hash);
				status_cracked(ans, word);
			}
		}
		fclose(fp);
		status_no_cracked();
	} else {
        help_menu(name);
    }
    printf("|> Finished.\n");
    return 0;
}

char *convert_to_md5(char *word) {
	unsigned char digest[MD5_SIZE];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, word, strlen(word));
    MD5_Final(digest, &ctx);
	static char result[SIZE];
    for (int i = 0; i < MD5_SIZE; i++) {
        sprintf(result + 2 * i, "%02x", digest[i]);
    }
    return result;
}

char *convert_to_sha1(char *word) {
	unsigned char digest[SHA1_SIZE];
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, word, strlen(word));
	SHA1_Final(digest, &ctx);
	static char result[SIZE];
	for (int i = 0; i < SHA1_SIZE; i++) {
		sprintf(result + 2 * i, "%02x", digest[i]);
	}
	return result;
}

char *extract_file(char *fitem) {
    FILE *fopen(), *fp;
    static char item[SIZE];
    if ((fp = fopen(fitem, "r")) == NULL) {
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		exit(1);
    }
    while (!feof(fp)) {
        fgets(item, SIZE, fp);
    }
    fclose(fp);
		item[strcspn(item, "\n")] = '\0';
    return item;
}

int verify_string(char *result, char *hash) {
	return strcmp(result, hash) == 0;
}

void status_cracked(int ans, char *word) {
	if (ans) {
        printf(
            "\r"
            "|\n"
            "|>================CRACKED================<|\n"
            "|                                         |\n"
            "|> PASSWORD...");
		bold();
        red();
        printf(" %s\n", word);
        reset();
        printf("|                                         |\n");
        printf("|>================CRACKED================<|\n");
		printf("|\n");
		printf("|> Finished.\n");
		exit(1);
	}
}

void status_no_cracked() {
	printf(
		"|\n"
		"|>================XXXXXXX================<|\n"
		"|                                         |\n"
		"|> NOT IN LIST...\n"
		"|                                         |\n"
		"|>================XXXXXXX================<|\n"
		"|\n");
}

void help_menu(char *name) {
    printf("|> Usage: %s <hash> <wordlist>\n"
           "|> Example: %s hash.txt rockyou.txt\n"
		   "\tOptions:\n"
	   	   "\t\t-h --help help for VaporCrack\n"
	   	   "\t\t-d --dictionnary <hash_file> <wordlist_file>\n"
		   "\t\t-a --algorithm <md5> | <sha1>\n", name, name);
}

void red() {
	printf("\033[1;31m");
}

void reset() {
	printf("\033[0m");
}

void bold() {
	printf("\e[1m");
}
