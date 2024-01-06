#include"headers.h"
void run(char **args, int no_args) {
    int status;
    pid_t pid = fork(), wpid;
    if (pid < 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        }
    else if(pid==0 && (execvp(args[0],args)<0)){
        perror("execvp");
        exit(EXIT_FAILURE);
    }
     else {
        waitpid(pid, &status, 0);
    }
}
