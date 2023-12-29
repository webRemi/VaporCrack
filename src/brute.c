/* cook potential words */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "chrono.h"
#include "verify.h"
#include "status.h"
#include "choice.h"
#include "brute.h"

char *brute(int length, int position, char *current, char *algo, char *hash, clock_t duration, long long wn, char *cook) {
	char *alpha_cook;
	int cook_size = 0;

	if (strcmp(cook, "lower") == 0) {
        alpha_cook = "abcdefghijklmnopqrstuvwxyz";
        cook_size = 26;
    } else if (strcmp(cook, "upper") == 0) {
        alpha_cook = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cook_size = 26;
    } else if (strcmp(cook, "number") == 0) {
        alpha_cook = "0123456789";
        cook_size = 10;
    } else if (strcmp(cook, "special") == 0) {
        alpha_cook = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
        cook_size = 33;
    } else if (strcmp(cook, "full") == 0) {
        alpha_cook = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ ";
        cook_size = 95;
    }

	if (position == length) {
		char *result = choice(algo, current);
		int ans = verify_string(result, hash);
		status_cracked(ans, current);
		status_time(show_time, duration, wn);
		return result;
	}

	for (int i = 0; i < cook_size; i++) {
		current[position] = alpha_cook[i];
		brute(length, position + 1, current, algo, hash, duration, wn, cook);
	}
}

