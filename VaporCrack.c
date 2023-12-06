/*|-----------------------|*/
/*|> VaporCrack.c ~ 4$X  <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <openssl/md4.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#define SIZE 500
#define MD4_SIZE 16
#define MD5_SIZE 16
#define SHA1_SIZE 20
#define SHA256_SIZE 32
#define SHA512_SIZE 64
#define BLAKE2S_SIZE 32
#define BLAKE2B_SIZE 64
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

char *convert_to_md4(char *word); // convert word to md4
char *convert_to_md5(char *word); // convert word to md5
char *convert_to_sha1(char *word); // convert word to sha1
char *convert_to_sha256(char *word); // convert word to sha256
char *convert_to_sha512(char *word); //convert word to sha512
char *convert_to_blake2s(char *word); // convert word to blake2s
char *convert_to_blake2b(char *word); // convert word to blake2b
char *extract_file(char *fitem); // extract item from file
int verify_string(char *result, char *hash); // compare converted word with hash
long int start_timer(); // start timer
double show_time(long int duration); // show time spent on cracking
void status_cracked(int ans, char *word); // display cracked status
void status_no_cracked(); // display no-cracked status
void help_menu(char *help); // display help menu
void red(); // set red color
void bold(); // set bold 
void reset(); // reset display effects

int main(int argc, char *argv[]) {
	printf(
    "  _                                                              \n"
    "- - _-                            ,- _~.                  ,,   \n"
    "  )-  )   _                      (' /|           _        ||   \n"
    "  )___)  < \\, -_-_   /'\\\\ ,._-_ ((  ||   ,._-_  < \\,  _-_ ||/\\ \n"
    " ~)___)  /-|| || \\\\ || ||  ||   ((  ||    ||    /-|| ||   ||_< \n"
    "  )  )  (( || || || || ||  ||    ( / |    ||   (( || ||   || | \n"
    " /-_/    \\/\\\\ ||-'  \\\\,/   \\\\,    -____-  \\\\,   \\/\\\\ \\\\,/ \\\\,\\\n"
    "              |/                                                 \n"
    "              '                                                 \n"
    "                      	                                     \n"
    );
    printf("|> Starting VaporCrack...\n");
	clock_t duration;
	duration = start_timer();
    char *name = argv[0];
    char *arg = argv[1];
	char *arg2 = argv[2];
	char *algo = argv[3];
    char *fhash = argv[4];
    char *fword = argv[5];
    if (argc == 6 && strcmp(arg, "-d") == 0) {
		printf("|> Mode: dictionnary\n");
		if (strcmp(arg2, "-a") == 0) 
			printf("|> Algorithm: %s\n", algo);
		char *hash = extract_file(fhash);
		FILE *fopen(), *fp;
		char word[SIZE];
		if ((fp = fopen(fword, "r")) == NULL) {
			fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		}
		printf("|> Cracking...\n");
		long long wn = 0;
		while (!feof(fp)) {
			wn++;
			fgets(word, SIZE, fp);
			word[strcspn(word, "\n")] = '\0';
			char *result;
			if (strcmp(algo, "md5") == 0)
				result = convert_to_md5(word);
			else if (strcmp(algo, "sha1") == 0)
				result = convert_to_sha1(word);
			else if (strcmp(algo, "sha256") == 0)
				result = convert_to_sha256(word);
			else if (strcmp(algo, "md4") == 0)
				result = convert_to_md4(word);
			else if (strcmp(algo, "sha512") == 0)
				result = convert_to_sha512(word);
			else if (strcmp(algo, "blake2b") == 0)
				result = convert_to_blake2b(word);
			else if (strcmp(algo, "blake2s") == 0) 
				result = convert_to_blake2s(word);
			int ans = verify_string(result, hash);
			status_cracked(ans, word);
			printf("\r|> Timer: %.2fsec | Attempt: %lld", show_time(duration), wn);
			fflush(stdout);
		}
		fclose(fp);
		status_no_cracked();
	} else {
        help_menu(name);
    }
    printf("|> Finished\n");
	return 0;
}

char *convert_to_md4(char *word) {
	unsigned char digest[MD4_SIZE];
	MD4_CTX ctx;
	MD4_Init(&ctx);
	MD4_Update(&ctx, word, strlen(word));
	MD4_Final(digest, &ctx);
	static char result[SIZE];
	for (int i = 0; i < MD4_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_md5(char *word) {
	unsigned char digest[MD5_SIZE];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, word, strlen(word));
    MD5_Final(digest, &ctx);
	static char result[SIZE];
    for (int i = 0; i < MD5_SIZE; i++)
        sprintf(result + 2 * i, "%02x", digest[i]);
    return result;
}

char *convert_to_sha1(char *word) {
	unsigned char digest[SHA1_SIZE];
	SHA_CTX ctx;
	SHA1_Init(&ctx);
	SHA1_Update(&ctx, word, strlen(word));
	SHA1_Final(digest, &ctx);
	static char result[SIZE];
	for (int i = 0; i < SHA1_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_sha256(char *word) {
	unsigned char digest[SHA256_SIZE];
	SHA256_CTX ctx;
	SHA256_Init(&ctx);
	SHA256_Update(&ctx, word, strlen(word));
	SHA256_Final(digest, &ctx);
	static char result[SIZE];
	for (int i = 0; i < SHA256_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *convert_to_sha512(char *word) {
	unsigned char digest[SHA512_SIZE];
	SHA512_CTX ctx;
	SHA512_Init(&ctx);
	SHA512_Update(&ctx, word, strlen(word));
	SHA512_Final(digest, &ctx);
	static char result[SIZE];
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
	static char result[SIZE];
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
	static char result[SIZE];
	for (int i = 0; i < BLAKE2B_SIZE; i++)
		sprintf(result + 2 * i, "%02x", digest[i]);
	return result;
}

char *extract_file(char *fitem) {
    FILE *fopen(), *fp;
    static char item[SIZE];
    if ((fp = fopen(fitem, "r")) == NULL) {
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		exit(1);
    }
    while (!feof(fp)) {
        fgets(item, SIZE, fp);
    }
    fclose(fp);
		item[strcspn(item, "\n")] = '\0';
    return item;
}

int verify_string(char *result, char *hash) {
	return strcmp(result, hash) == 0;
}

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

void status_cracked(int ans, char *word) {
	if (ans) {
        printf(
            "\r"
            "|>================CRACKED================<|\n"
            "|                                         |\n"
            "|>");
		bold();
        red();
        printf(" %s\n", word);
        reset();
        printf("|                                         |\n");
        printf("|>================CRACKED================<|\n");
		printf("|> Finished\n");
		exit(0);
	}
}

void status_no_cracked() {
	printf(
		"|>================XXXXXXX================<|\n"
		"|                                         |\n"
		"|> NOT IN LIST\n"
		"|                                         |\n"
		"|>================XXXXXXX================<|\n"
	);
}

void help_menu(char *name) {
    printf("|> Usage: %s <hash> <wordlist>\n"
           "|> Example: %s hash.txt rockyou.txt\n"
		   "\tOptions:\n"
	   	   "\t\t-h --help help for VaporCrack\n"
	   	   "\t\t-d --dictionnary <hash_file> <wordlist_file>\n"
		   "\t\t-a --algorithm <md5> | <sha1>\n", name, name);
}

void red() {
	printf("\033[1;31m");
}

void reset() {
	printf("\033[0m");
}

void bold() {
	printf("\e[1m");
}
