/* cook potential words */

#include <stdio.h>
#include <time.h>
#include "chrono.h"
#include "verify.h"
#include "status.h"
#include "choice.h"
#include "brute.h"

char *brute(int length, int position, char *current, char *algo, char *hash, clock_t duration, long long wn) {
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	if (position == length) {
		char *result = choice(algo, current);
		int ans = verify_string(result, hash);
		status_cracked(ans, current);
		printf("\r|> Timer: %.2fsec | Attempt: %lld", show_time(duration), wn);
		fflush(stdout);
		return result;
	}
	for (int i = 0; i < 26; i++) {
		current[position] = alphabet[i];
		brute(length, position + 1, current, algo, hash, duration, wn);
	}
}

