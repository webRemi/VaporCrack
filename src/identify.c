/* idenfity hash format */

#include <stdio.h>
#include <string.h>
#include "identify.h"

void identify(char *hash) {

	struct hash_points {
    	int md4, halfmd5, md5, sha1, sha256, sha512, blake2s, blake2b, ripemd160, whirlpool, sm3, ntlm;
	};

	struct hash_points points = {0};
	struct hash_points *ptr = &points;

	size_t size = strlen(hash);

	switch(size) {
		case 16:
			points.halfmd5++;
			break;
		case 32:
			points.md4++;
			points.md5++;
			points.ntlm++;
			break;
		case 40:
			points.sha1++;
			points.ripemd160++;
			break;
		case 64:
			points.sha256++;
			points.blake2s++;
			points.sm3++;
			break;
		case 128:
			points.sha512++;
			points.blake2b++;
			points.whirlpool++;
			break;
	}
	if (ptr->md4 >= 1) puts("|=> md4");
	if (ptr->md5 >= 1) puts("|=> md5");
	if (ptr->ntlm >= 1) puts("|=> ntlm");
	if (ptr->halfmd5 >=1) puts("|=> halfmd5");
	if (ptr->sha1 >= 1) puts("|=> sha1");
	if (ptr->ripemd160 >= 1) puts("|=> ripemd160");
	if (ptr->sha256 >= 1) puts("|=> sha256");
	if (ptr->sm3 >= 1) puts("|=> sm3");
	if (ptr->sha512 >= 1) puts("|=> sha512");
	if (ptr->blake2b >= 1) puts("|=> blake2b");
	if (ptr->whirlpool >= 1) puts("|=> whirlpool");
}
