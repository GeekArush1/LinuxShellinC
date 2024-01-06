#include"headers.h"
void proclore(char *pid_str) {
    int pid = getpid(); // Default to the shell's PID if no argument is provided
    if (pid_str) {
        pid = atoi(pid_str);
    }

    // Get process status
    char status_str[10];
    FILE *status_file = fopen("/proc/self/status", "r");
    if (status_file) {
        while (fgets(status_str, sizeof(status_str), status_file)) {
            if (strstr(status_str, "State:") == status_str) {
                break;
            }
        }
        fclose(status_file);
    }

    // Get process group
    pid_t process_group = getpgrp();

    // Get virtual memory
    char vm_size_str[50];
    FILE *statm_file = fopen("/proc/self/statm", "r");
    if (statm_file) {
        fscanf(statm_file, "%s", vm_size_str);
        fclose(statm_file);
    }

    // Get executable path
    char executable_path[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", executable_path, sizeof(executable_path));
    if (len != -1) {
        executable_path[len] = '\0';
        // Convert the executable path to a relative path if it is in the home directory
        if (strstr(executable_path, HOME_DIRECTORY) == executable_path) {
            memmove(executable_path, executable_path + strlen(HOME_DIRECTORY), len - strlen(HOME_DIRECTORY) + 1);
            sprintf(executable_path, "%s%s", HOME_DIRECTORY, executable_path + strlen("~"));
        }
    }

    // Print the process information
    printf("pid : %d\n", pid);
    printf("process status : %s\n", status_str);
    printf("Process Group : %d\n", process_group);
    printf("Virtual memory : %s\n", vm_size_str);
    printf("executable path : %s\n", executable_path);
}
