#include "headers.h"
void init_shell() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        char *system_name = "ArushSachdeva";
        printf("%s@Shell:%s> ", system_name, cwd);
    } else {
        perror("getcwd");
    }
}
