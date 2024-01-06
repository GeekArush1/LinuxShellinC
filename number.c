#include"headers.h"
void number(char *input) {
    char *r = strtok(input, ";");
    while (r != NULL) {
        n++;
        r = strtok(NULL, ";");
    }
}
