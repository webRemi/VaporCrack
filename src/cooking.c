/* cook potential word */

#include <time.h>
#include "brute.h"

void cooking(char *arg2, char *algo, char *fhash, char *cook, char *hash, clock_t duration) {
	int length = 0;
	int ans = 0; 
	char current[8] = {'\0'};
	long long wn = 0;
	while (!ans) {
		brute(length, 0, current, algo, hash, duration, wn, cook);
		length++;
	}
}
