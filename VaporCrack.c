/*|-----------------------|*/
/*|> VaporCrack.c ~ 4$X <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <openssl/md5.h>
#include <string.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

char *convert_to_md5(char *result, char *password); // convert word to md5
int verify_string(char *result, char *hash); // compare converted word with hash
void help_menu(char *name); // display help menu

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
    char *hash = argv[2];
    char *word = argv[3];
    if (argc == 4 && strcmp(arg, "-d") == 0) {
	char *result = convert_to_md5(result, word);
	int ans = verify_string(result, hash);
	if (ans) {
	    printf("|\n"
	           "|>================CRACKED================<|\n"
		   "|                                         |\n"
		   "|> PASSWORD... %s\n"
		   "|                                         |\n"
		   "|>================CRACKED================<|\n"
		   "|\n"
		   ,word);
	} else {
	    printf("|\n"
	           "|>================XXXXXXX================<|\n"
		   "|\n");
	}
    } else {
        help_menu(name);
    }
    printf("|> Finished.\n");
    return 0;
}

char *convert_to_md5(char *result, char *password) {
    unsigned char digest[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, password, strlen(password));
    MD5_Final(digest, &ctx);

    for (int i = 0; i < 16; i++) {
        sprintf(result + 2 * i, "%02x", digest[i]);
    }
    return result;
}

int verify_string(char *result, char *hash) {
    return strcmp(result, hash) == 0;
}

void help_menu(char *name) {
	printf("|> Usage: %s <hash> <wordlist>\n"
	       "|> Example: %s hash.txt rockyou.txt\n"
	       "\tOptions:\n"
	       "\t\t-h --help help for VaporCrack\n"
	       "\t\t-d --dictionnary <hash_file> <wordlist_file>\n", name, name);
}
