/* start chrono */

#include <time.h>
#include "chrono.h"

long int start_timer() {
	clock_t t;
	t = 0;
	return t;
}

double show_time(long int duration) {
	duration = clock() - duration;
	double actual_time = ((double)duration)/CLOCKS_PER_SEC;;
	return actual_time;
}
