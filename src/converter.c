/* convert word to hash */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/md4.h>
#include <openssl/whrlpool.h>
#include "converter.h"
#define SIZE 100
#define MD4_SIZE 16
#define HALFMD5_SIZE 8
#define MD5_SIZE 16
#define SHA1_SIZE 20
#define SHA256_SIZE 32
#define SHA512_SIZE 64
#define BLAKE2S_SIZE 32
#define BLAKE2B_SIZE 64
#define RIPEMD160_SIZE 20
#define WHIRLPOOL_SIZE 64 
#define SM3_SIZE 32
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

/*char *convert_to_md4(char *word) {
	unsigned char digest[MD4_SIZE];
	const EVP_MD *md = EVP_md4();
	EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * MD4_SIZE + 1);
    if (result == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
	for (int i = 0; i < MD4_SIZE; i++) 
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}*/

char *convert_to_md4(char *word) {
	unsigned char digest[MD4_SIZE];
	MD4_CTX ctx;
	MD4_Init(&ctx);
	MD4_Update(&ctx, word, strlen(word));
	MD4_Final(digest, &ctx);
	char *result = malloc(2 * MD4_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < MD4_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_halfmd5(char *word) {
	unsigned char digest[MD5_SIZE];
	const EVP_MD *md = EVP_md5();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * HALFMD5_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < HALFMD5_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_md5(char *word) {
	unsigned char digest[MD5_SIZE];
	const EVP_MD *md = EVP_md5();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * MD5_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < MD5_SIZE; i++) 
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_sha1(char *word) {
	unsigned char digest[SHA1_SIZE];
	const EVP_MD *md = EVP_sha1();
	EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * SHA1_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < SHA1_SIZE; i++) 
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_sha256(char *word) {
	unsigned char digest[SHA256_SIZE];
	const EVP_MD *md = EVP_sha256();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * SHA256_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
 	}
	for (int i = 0; i < SHA256_SIZE; i++) 
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_sha512(char *word) {
	unsigned char digest[SHA512_SIZE];
	const EVP_MD *md = EVP_sha512();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * SHA512_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < SHA512_SIZE; i++) 
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_blake2s(char *word) {
	unsigned char digest[BLAKE2S_SIZE];
	const EVP_MD *md = EVP_blake2s256();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * BLAKE2S_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < BLAKE2S_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_blake2b(char *word) {
	unsigned char digest[BLAKE2B_SIZE];
	const EVP_MD *md = EVP_blake2b512();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * BLAKE2B_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < BLAKE2B_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_ripemd160(char *word) {
	unsigned char digest[RIPEMD160_SIZE];
	const EVP_MD *md = EVP_ripemd160();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * RIPEMD160_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < RIPEMD160_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

/*char *convert_to_whirlpool(char *word) {
	unsigned char digest[WHIRLPOOL_SIZE];
	const EVP_MD *md = EVP_whirlpool();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	puts("before update");
	EVP_DigestUpdate(mdctx, word, strlen(word));
	puts("after uppdate");
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * WHIRLPOOL_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < WHIRLPOOL_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}*/

char *convert_to_whirlpool(char *word) {
	unsigned char digest[WHIRLPOOL_SIZE];
	WHIRLPOOL_CTX ctx;
	WHIRLPOOL_Init(&ctx);
	WHIRLPOOL_Update(&ctx, word, strlen(word));
	WHIRLPOOL_Final(digest, &ctx);
	char *result = malloc(2 * WHIRLPOOL_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < WHIRLPOOL_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_sm3(char *word) {
	unsigned char digest[SM3_SIZE];
	const EVP_MD *md = EVP_sm3();
	EVP_MD_CTX *mdctx;
	mdctx = EVP_MD_CTX_new();
	EVP_DigestInit_ex(mdctx, md, NULL);
	EVP_DigestUpdate(mdctx, word, strlen(word));
	EVP_DigestFinal(mdctx, digest, NULL);
	EVP_MD_CTX_free(mdctx);
	char *result = malloc(2 * SM3_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < SM3_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_ntlm(char *word) {
	unsigned char *utf16le = malloc(2 * strlen(word) + 1);
	if (utf16le == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	int i = 0, j = 0;
	while(word[i] != '\0') {
		utf16le[j++] = word[i++];
		utf16le[j++] = 0;
	}
	utf16le[j] = 0;
	unsigned char digest[MD4_SIZE];
	MD4_CTX ctx;
	MD4_Init(&ctx);
	MD4_Update(&ctx, utf16le, j);
	MD4_Final(digest, &ctx);
	char *result = malloc(2 * MD4_SIZE + 1);
	if (result == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		exit(1);
	}
	for (int i = 0; i < MD4_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}
