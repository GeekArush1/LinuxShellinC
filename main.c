#include"headers.h"
char pastevents[MAX_HISTORY][2000];
int pastevents_count=0;
int n = 0;
char HOME_DIRECTORY[PATH_MAX];
int main() {
    if (getcwd(HOME_DIRECTORY, sizeof(HOME_DIRECTORY)) == NULL) {
        perror("getcwd");
        return 1;
    }
    shell();
    return 0;
}
