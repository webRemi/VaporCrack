/* combinate two different of sibling wordlists */

#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "choice.h"
#include "chrono.h"
#include "status.h"
#include "verify.h"
#define SIZE 500

void combinator(char *arg2, char *algo, char *fhash, char *fword, char *fword2, char *hash, clock_t duration) {
	FILE *fopen(), *fp, *fp2;
	char word[SIZE];
	if ((fp = fopen(fword, "r")) == NULL)
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
	long long wn = 0;
	while (fgets(word, SIZE, fp)) {
		word[strcspn(word, "\n")] = '\0';
		char word2[SIZE];
    	if ((fp2 = fopen(fword2, "r")) == NULL)
			fprintf(stderr, "Error opening file: %s\n", strerror(errno));
    	while (fgets(word2, SIZE, fp2)) {
			wn++;
 			word2[strcspn(word2, "\n")] = '\0';
			char word_combined[SIZE];
			strcpy(word_combined, word);
			strcat(word_combined, word2);
			char *result;
			result = choice(algo, word_combined);
			int ans = verify_string(result, hash);
			status_cracked(ans, word_combined);
			status_time(show_time, duration, wn);
		}
		fclose(fp2);
	}
	fclose(fp);
}
