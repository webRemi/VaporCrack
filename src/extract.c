/* extract from file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "extract.h"
#define SIZE 500

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

