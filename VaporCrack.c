#include <stdio.h>
#include <openssl/md5.h>
#include <string.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

char *convert_to_md5(char *result, char *password);
int verify_string(char *result, char *hash);

int main() {
    char *hash = "5d41402abc4b2a76b9719d911017c592";
    char *password = "hello";
    char *result = convert_to_md5(result, password);
    int ans = verify_string(result, hash);
    printf("ans: %d\n", ans);
    printf("word: %s\n", password);

    return 0;
}

char *convert_to_md5(char *result, char *password) {
    unsigned char digest[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, password, strlen(password));
    MD5_Final(digest, &ctx);

    for (int i = 0; i < 16; i++) {
        sprintf(result + 2 * i, "%02x", digest[i]);
    }
    return result;
}

int verify_string(char *result, char *hash) {
    return strcmp(result, hash) == 0;
}

