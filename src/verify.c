/* verify words and hashes */

#include <string.h>
#include "verify.h"

int verify_string(char *result, char *hash) {
	return strcmp(result, hash) == 0;
}
