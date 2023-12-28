/*|-----------------------|*/
/*|> VaporCrack.c ~ 4$X  <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "help.h"
#include "status.h"
#include "color.h"
#include "chrono.h"
#include "converter.h"
#include "choice.h"
#include "extract.h"
#include "brute.h"
#include "verify.h"
#include "identify.h"
#include "cooking.h"
#include "combinator.h"
#include "dictionary.h"

int main(int argc, char *argv[]) {
	puts(
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
    puts("|> Starting VaporCrack...");
	clock_t duration = start_timer();
	char *name = argv[0];
    char *arg = argv[1];
	char *arg2 = argv[2];
    if (argc == 6 && strcmp(arg, "-d") == 0) {
		unsigned int mark = 1;
		char *mode = "dictionary";
		char *algo = argv[3];
		char *fhash = argv[4];
		char *fword = argv[5];
		char *hash = extract_file(fhash);
		printf("|> Mode: %s\n", mode);
		printf("|> Algorithm: %s\n", algo);
		puts("|> Cracking...");
		dictionary(arg2, algo, fhash, fword, hash, duration);
	} else if (argc == 7 && strcmp(arg, "-c") == 0) {
		unsigned int mark = 1;
		char *mode = "combinator";
		char *algo = argv[3];
		char *fhash = argv[4];
		char *fword = argv[5];
		char *fword2 = argv[6];
		char *hash = extract_file(fhash);
		printf("|> Mode: %s\n", mode);
		printf("|> Algorithm: %s\n", algo);
		puts("|> Cracking...");
		combinator(arg2, algo, fhash, fword, fword2, hash, duration);
	} else if (argc == 6 && strcmp(arg, "-b") == 0) {
		unsigned int mark = 2;
		char *mode = "brute";
		char *algo = argv[3];
		char *fhash = argv[4];
		char *cook = argv[5];
		char *hash = extract_file(fhash);
		printf("|> Mode: %s\n", mode);
		printf("|> Algorithm: %s\n", algo);
		printf("|> Cook: %s\n", cook);
		puts("|> Cracking...");
		cooking(arg2, algo, fhash, cook, hash, duration);
	} else if (argc == 3 && strcmp(arg, "-i") == 0) {
		unsigned int mark = 3;
		char *mode = "identify";
		char *fhash = argv[2];
		char *hash = extract_file(fhash);
		printf("|> Mode: %s\n", mode);
		puts("|> Analyzing...");
		identify(hash);
	} else {
		help_menu(name);
	}
    puts("|> Finished");
	return 0;
}
