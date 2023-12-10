/*|-----------------------|*/
/*|> VaporCrack.c ~ 4$X  <|*/
/*|-----------------------|*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <openssl/evp.h>
#include <openssl/md4.h>
#define SIZE 500
#define MD4_SIZE 16
#define HALFMD5_SIZE 8
#define MD5_SIZE 16
#define SHA1_SIZE 20
#define SHA256_SIZE 32
#define SHA512_SIZE 64
#define BLAKE2S_SIZE 32
#define BLAKE2B_SIZE 64
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

char *brute(int length, int position, char *current, char *algo, char *hash); // cook potential words
char *choice(char *algo, char *word); // choose the right algo to convert
char *convert_to_md4(char *word); // convert word to md4
char *convert_to_halfmd5(char *word); // convert word to halfmd5
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
	puts(
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
    puts("|> Starting VaporCrack...");
	clock_t duration;
	duration = start_timer();
    char *name = argv[0];
    char *arg = argv[1];
	char *arg2 = argv[2];
	char *algo = argv[3];
	char *fhash = argv[4];
    if (argc == 6 && strcmp(arg, "-d") == 0) {
		char *arg2 = argv[2];
		char *algo = argv[3];
		char *fhash = argv[4];
		char *fword = argv[5];
		puts("|> Mode: dictionnary");
		if (strcmp(arg2, "-a") == 0) 
			printf("|> Algorithm: %s\n", algo);
		char *hash = extract_file(fhash);
		FILE *fopen(), *fp;
		char word[SIZE];
		if ((fp = fopen(fword, "r")) == NULL) {
			fprintf(stderr, "Error opening file: %s\n", strerror(errno));
		}
		puts("|> Cracking...");
		long long wn = 0;
		while (!feof(fp)) {
			wn++;
			fgets(word, SIZE, fp);
			word[strcspn(word, "\n")] = '\0';
			char *result;
			result = choice(algo, word);
			int ans = verify_string(result, hash);
			status_cracked(ans, word);
			printf("\r|> Timer: %.2fsec | Attempt: %lld", show_time(duration), wn);
			fflush(stdout);
		}
		fclose(fp);
		status_no_cracked();
	} else if (argc == 5 && strcmp(arg, "-b") == 0) {
		puts("|> Mode: brute");
		if (strcmp(arg2, "-a") == 0) 
			printf("|> Algorithm: %s\n", algo);
		char *hash = extract_file(fhash);
		puts("|> Cracking...");
		int length = 0;
		int ans = 0;
		char current[8] = {'\0'};
		while (!ans) {
			brute(length, 0, current, algo, hash);
			//result = choice(algo, current);
			//printf("%s\n", result);
			//printf("%s\n", current);
			//int ans = verify_string(result, hash);
			//status_cracked(ans, current);
			/*if (strcmp(algo, "md4") == 0)
				result = convert_to_md4(word);
			else if (strcmp(algo, "halfmd5") == 0) 
				result = convert_to_halfmd5(word);
			else if (strcmp(algo, "md5") == 0)
				result = convert_to_md5(word);
			else if (strcmp(algo, "sha1") == 0)
				result = convert_to_sha1(word);
			else if (strcmp(algo, "sha256") == 0)
				result = convert_to_sha256(word);
			else if (strcmp(algo, "sha512") == 0)
				result = convert_to_sha512(word);
			else if (strcmp(algo, "blake2s") == 0)
				result = convert_to_blake2s(word);
			else if (strcmp(algo, "blake2b") == 0) 
				result = convert_to_blake2b(word);
			ans = verify_string(result, hash);
			//printf("%s\n", result);
			free(result);
			status_cracked(ans, result);*/
			length++;
		}
	} else {
        help_menu(name);
    }
    puts("|> Finished");
	return 0;
}

char *choice(char *algo, char *word) {
	char *result;
	if (strcmp(algo, "md4") == 0)
		result = convert_to_md4(word);
	else if (strcmp(algo, "halfmd5") == 0) 
		result = convert_to_halfmd5(word);
	else if (strcmp(algo, "md5") == 0)
		result = convert_to_md5(word);
	else if (strcmp(algo, "sha1") == 0)
		result = convert_to_sha1(word);
	else if (strcmp(algo, "sha256") == 0)
		result = convert_to_sha256(word);
	else if (strcmp(algo, "sha512") == 0)
	 	result  = convert_to_sha512(word);
	else if (strcmp(algo, "blake2s") == 0)
		result = convert_to_blake2s(word);
	else if (strcmp(algo, "blake2b") == 0) 
		result = convert_to_blake2b(word);
	return result;
}

char *brute(int length, int position, char *current, char *algo, char *hash) {
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	if (position == length) {
		//char *result = choice(algo, current);
		char *result = convert_to_md5(current);
		printf("%s\n", current);
		printf("%s\n", result);
		int ans = verify_string(result, hash);
		printf("%d\n", ans);
		status_cracked(ans, current);
		return result;
	}
	for (int i = 0; i < 26; i++) {
		current[position] = alphabet[i];
		brute(length, position + 1, current, algo, hash);
	}
}

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
        puts("|                                         |");
        puts("|>================CRACKED================<|");
		puts("|> Finished");
		exit(0);
	}
}

void status_no_cracked() {
	puts(
		"\n|>================XXXXXXX================<|\n"
		"|                                         |\n"
		"|> NOT IN LIST\n"
		"|                                         |\n"
		"|>================XXXXXXX================<|"
	);
}

void help_menu(char *name) {
    printf("|> Usage: %s <hash> <wordlist>\n"
           "|> Example: %s hash.txt rockyou.txt\n"
		   "\tOptions:\n"
	   	   "\t\t-h --help help for VaporCrack\n"
		   "\t\t-b --brute <hash_file>\n"
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
