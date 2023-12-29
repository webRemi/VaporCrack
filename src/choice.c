/* select correct algorithm */

#include <string.h>
#include "choice.h"
#include "converter.h"

char *choice(char *algo, char *word) {
	char *result;
	if (strcmp(algo, "md4") == 0) result = convert_to_md4(word);
	else if (strcmp(algo, "halfmd5") == 0) result = convert_to_halfmd5(word);
	else if (strcmp(algo, "md5") == 0) result = convert_to_md5(word);
	else if (strcmp(algo, "sha1") == 0) result = convert_to_sha1(word);
	else if (strcmp(algo, "sha256") == 0) result = convert_to_sha256(word);
	else if (strcmp(algo, "sha512") == 0) result  = convert_to_sha512(word);
	else if (strcmp(algo, "blake2s") == 0) result = convert_to_blake2s(word);
	else if (strcmp(algo, "blake2b") == 0) result = convert_to_blake2b(word);
	else if (strcmp(algo, "ripemd160") == 0) result = convert_to_ripemd160(word);
	else if (strcmp(algo, "whirlpool") == 0) result = convert_to_whirlpool(word);
	else if (strcmp(algo, "sm3") == 0) result = convert_to_sm3(word);
	else if (strcmp(algo, "ntlm") == 0) result = convert_to_ntlm(word);
	return result;
}

