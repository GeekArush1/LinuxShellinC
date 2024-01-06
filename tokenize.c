#include "headers.h"
char **tokenize(char *input) {
    char *p = strtok(input, ";");
    char **array = malloc(256 * sizeof(char *));
    int no = 0;
    while (p != NULL) {
        array[no++] = p;
        p = strtok(NULL, ";");
    }
    return array;
}
