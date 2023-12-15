/* Display help menu */

#include <stdio.h>
#include "help_menu.h"

void help_menu(char *name) {
    printf("|> Usage: %s <hash> <wordlist>\n"
           "|> Example: %s hash.txt rockyou.txt\n"
		  "\tOptions:\n"
	  	  "\t\t-h --help help for VaporCrack\n"
		  "\t\t-b --brute <hash_file>\n"
	  	  "\t\t-d --dictionnary <hash_file> <wordlist_file>\n"
		  "\t\t-a --algorithm <md5> | <sha1>\n", name, name);
}
