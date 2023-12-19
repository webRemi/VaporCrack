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
#define SIZE 500

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
	clock_t duration;
	duration = start_timer();
    char *name = argv[0];
    char *arg = argv[1];
    if (argc == 6 && strcmp(arg, "-d") == 0) {
		char *arg2 = argv[2];
		char *algo = argv[3];
		char *fhash = argv[4];
		char *fword = argv[5];
		char *hash = extract_file(fhash);
		puts("|> Mode: dictionnary");
		if (strcmp(arg2, "-a") == 0) 
			printf("|> Algorithm: %s\n", algo);
		FILE *fopen(), *fp;
		char word[SIZE];
		if ((fp = fopen(fword, "r")) == NULL) {
			fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		}
		puts("|> Cracking...");
		long long wn = 0;
		while (!feof(fp)) {
			wn++;
			fgets(word, SIZE, fp);
			word[strcspn(word, "\n")] = '\0';
			char *result;
			result = choice(algo, word);
			int ans = verify_string(result, hash);
			status_cracked(ans, word);
			printf("\r|> Timer: %.2fsec | Attempt: %lld", show_time(duration), wn);
			fflush(stdout);
		}
		fclose(fp);
		status_no_cracked();
	} else if (argc == 6 && strcmp(arg, "-b") == 0) {
		char *arg2 = argv[2];
		char *algo = argv[3];
		char *fhash = argv[4];
		char *cook = argv[5];
		char *hash = extract_file(fhash);
		puts("|> Mode: brute");
		if (strcmp(arg2, "-a") == 0) 
			printf("|> Algorithm: %s\n", algo);
		printf("|> Cook: %s\n", cook);
		puts("|> Cracking...");
		int length = 0;
		int ans = 0;
		char current[8] = {'\0'};
		long long wn = 0;
		while (!ans) {
			brute(length, 0, current, algo, hash, duration, wn, cook);
			length++;
		}
	} else if (argc == 3 && strcmp(arg, "-i") == 0) {
		char *fhash = argv[2];
		char *hash = extract_file(fhash);
		puts("|> Mode identify");
		puts("|> Analyzing...");
		identify(hash);
	} else {
        help_menu(name);
    }
    puts("|> Finished");
	return 0;
}
