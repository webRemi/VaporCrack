/* crack word using wordlist */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "chrono.h"
#include "choice.h"
#include "verify.h"
#include "status.h"
#define SIZE 500

void dictionary(char *arg2, char *algo, char *fhash, char *fword, char *hash, clock_t duration) {
	FILE *fopen(), *fp;
	char word[SIZE];
	if ((fp = fopen(fword, "r")) == NULL)
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
	long long wn = 0;
	while (!feof(fp)) {
		wn++;
		fgets(word, SIZE, fp);
		word[strcspn(word, "\n")] = '\0';
		char *result;
		result = choice(algo, word);
		int ans = verify_string(result, hash);
		status_cracked(ans, word);
		status_time(show_time, duration, wn);
	}
	fclose(fp);
	status_no_cracked();
}
