/* display status crack */

#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "color.h"
<<<<<<< HEAD
#include "chrono.h"
=======
>>>>>>> origin/main

void status_cracked(int ans, char *word) {
	if (ans) {
        printf(
            "\r"
            "|>================CRACKED================<|\n"
            "|                                         |\n"
            "|>");
		bold();
        red();
        printf(" %s\n", word);
        reset();
        puts("|                                         |");
        puts("|>================CRACKED================<|");
		puts("|> Finished");
		exit(0);
	}
}

void status_no_cracked() {
	puts(
		"\n|>================XXXXXXX================<|\n"
		"|                                         |\n"
		"|> NOT IN LIST\n"
		"|                                         |\n"
		"|>================XXXXXXX================<|"
	);
}
<<<<<<< HEAD

void status_time(double (*show_time)(), clock_t duration, long long wn) {
	printf("\r|> Timer: %.2fsec | Attempt: %lld", show_time(duration), wn);
	fflush(stdout);
}
=======
>>>>>>> origin/main
