/*|-----------------------|*/
/*|> VaporCrack.c ~ 4$X <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <openssl/md5.h>
#define SIZE 100
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

char *convert_to_md5(char *word); // convert word to md5
char *extract_file(char *fitem); // extract iitem from file
int verify_string(char *result, char *hash); // compare converted word with hash
void status(int ans, char *word); // display cracking status
void help_menu(char *help); // display help menu

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
    char *fhash = argv[2];
    char *fword = argv[3];
    if (argc == 4 && strcmp(arg, "-d") == 0) {
		char *hash = extract_file(fhash);
		FILE *fopen(), *fp;
		char word[SIZE];
		if ((fp = fopen(fword, "r")) == NULL) {
			fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		}
		while (!feof(fp)) {
			fgets(word, SIZE, fp);
			word[strcspn(word, "\n")] = '\0';
			char *result = convert_to_md5(word);
			int ans = verify_string(result, hash);
			status(ans, word);
		}
		fclose(fp);
	} else {
        help_menu(name);
    }
    printf("|> Finished.\n");
    return 0;
}

char *convert_to_md5(char *word) {
	unsigned char digest[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, word, strlen(word));
    MD5_Final(digest, &ctx);
	static char result[SIZE];
    for (int i = 0; i < 16; i++) {
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
	return strncmp(result, hash, 33) == 0;
}

void status(int ans, char *word) {
	if (ans) {
	    printf(
            "|\n"
	    	"|>================CRACKED================<|\n"
	    	"|                                         |\n"
	    	"|> PASSWORD... %s\n"
            "|                                         |\n"
            "|>================CRACKED================<|\n"
            "|\n", word);
		exit(1);
	} else {
	    printf(
            "|\n"
	    	"|>================XXXXXXX================<|\n"
			"|                                         |\n"
			"|> TRYING... %s\n" 
			"|                                         |\n"
			"|>================XXXXXXX================<|\n"
            "|\n", word);
	}
}

void help_menu(char *name) {
    printf("|> Usage: %s <hash> <wordlist>\n"
           "|> Example: %s hash.txt rockyou.txt\n"
		   "\tOptions:\n"
	   	   "\t\t-h --help help for VaporCrack\n"
	   	   "\t\t-d --dictionnary <hash_file> <wordlist_file>\n", name, name);
}
