/* display status crack */

#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "color.h"

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
