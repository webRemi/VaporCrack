/* enable and disable colors */

#include <stdio.h>
#include "color.h"

void red() {
	printf("\033[1;31m");
}

void reset() {
	printf("\033[0m");
}

void bold() {
	printf("\e[1m");
}
