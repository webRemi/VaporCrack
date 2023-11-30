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

char *convert_to_md5(char *result, char *fword); // convert word to md5
char *extract_hash(char *fhash); // extract hash from file
int verify_string(char *result, char *hash); // compare converted word with hash
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
				char *hash = extract_hash(fhash);
				char *result = convert_to_md5(result, fword);
				int ans = verify_string(result, hash);
				if (ans) {
	    			printf(
            "|\n"
	    			"|>================CRACKED================<|\n"
	    			"|                                         |\n"
	    			"|> PASSWORD... \n"
            "|                                         |\n"
            "|>================CRACKED================<|\n"
            "|\n");
        } else {
	    			printf(
            "|\n"
	    			"|>================XXXXXXX================<|\n"
            "|\n");
				}
    } else {
        help_menu(name);
    }
    printf("|> Finished.\n");
    return 0;
}

char *convert_to_md5(char *result, char *fword) {
		FILE *fopen(), *fp;
		static char word[SIZE];
		if ((fp = fopen(fword, "r")) == NULL) {
				fprintf(stderr, "Error opening file: %s\n", strerror(errno));
				exit(1);
    }
    while (!feof(fp)) {
        fgets(word, SIZE, fp);
    }
    fclose(fp);
		word[strcspn(word, "\n")] = '\0';
    unsigned char digest[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, word, strlen(word));
    MD5_Final(digest, &ctx);

    for (int i = 0; i < 16; i++) {
        sprintf(result + 2 * i, "%02x", digest[i]);
    }
    return result;
}

char *extract_hash(char *fhash) {
    FILE *fopen(), *fp;
    static char hash[SIZE];
    if ((fp = fopen(fhash, "r")) == NULL) {
				fprintf(stderr, "Error opening file: %s\n", strerror(errno));
				exit(1);
    }
    while (!feof(fp)) {
        fgets(hash, SIZE, fp);
    }
    fclose(fp);
		hash[strcspn(hash, "\n")] = '\0';
    return hash;
}

int verify_string(char *result, char *hash) {
		return strncmp(result, hash, 33) == 0;
}

void help_menu(char *name) {
    printf("|> Usage: %s <hash> <wordlist>\n"
           "|> Example: %s hash.txt rockyou.txt\n"
	   "\tOptions:\n"
	   "\t\t-h --help help for VaporCrack\n"
	   "\t\t-d --dictionnary <hash_file> <wordlist_file>\n", name, name);
}
