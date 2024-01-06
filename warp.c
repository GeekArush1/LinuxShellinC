#include"headers.h"
void warp(char *command) {
    command += 4; // Move the pointer past "warp"
    char cwd[PATH_MAX];
    int flag=0;
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return;
    }
    else if (strlen(command) == 0) {
        // No argument provided, warp to home directory
        struct passwd *pw = getpwuid(getuid());
        if (pw) {
            chdir(pw->pw_dir);
   	    flag=1;
        }
    } 
    else {
        // Check for special directory flags
        if (strcmp(command, ".") == 0) {
           flag=1;
            // Current directory, no action needed
        } 
        else if (strcmp(command, "..") == 0) {
            chdir(".."); // Move to parent directory
            flag=1;
        } 
        else if (strcmp(command, "~") == 0) {
            // User's home directory
            struct passwd *pw = getpwuid(getuid());
            if (pw) {
                chdir(pw->pw_dir);
                flag=1;
            }
        } 
        else if (strcmp(command, "-") == 0) {
            // Previous working directory
            char *previousDir = getenv("OLDPWD");
            if (previousDir) {
                chdir(previousDir);
                flag=1;
            }
        } 
        else {
            if (command[0] == '/') {
                // Absolute path
                chdir(command);
                flag=1;
            } 
            else if (command[0] == '~' && (command[1] == '\0' || command[1] == '/')) {
                // Home directory path
                struct passwd *pw = getpwuid(getuid());
                if (pw) {
                    chdir(pw->pw_dir);
                    if (command[1] == '/') {
                        // Move to a subdirectory in the home directory
                        chdir(command + 2);
                        flag=1;
                    }
                }
            } 
        }
    }

    // Print the full path of the working directory after changing
    if(getcwd(cwd, sizeof(cwd)) != NULL && flag==1){
    	printf("%s\n", cwd);
    }
}
