#include"headers.h"
void removeSpaces(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            str[count++] = str[i];
        }
    }
}
