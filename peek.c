#include"headers.h"
void peek(char *flags, char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    struct stat fileStat;
    
    int show_all = 0;
    int show_details = 0;
    
    // Check if flags contain -a and/or -l
    if (flags) {
        if (strstr(flags, "-a") != NULL) {
            show_all = 1;
        }
        if (strstr(flags, "-l") != NULL) {
            show_details = 1;
        }
        if (strstr(flags,"-la")!=NULL){
            show_details=1;
            show_all=1;
        }
        if(strstr(flags,"-al")!=NULL){
            show_all=1;
            show_details=1;
        }
    }
    if (!path) {
        path = "."; // Current working directory if no path provided
    }
    while ((entry = readdir(dir)) != NULL) {
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (lstat(fullpath, &fileStat) < 0) {
            perror("lstat");
            continue;
        }

        // Determine the type of file for display
        char *type = "";
        if (S_ISDIR(fileStat.st_mode)) {
            type = "\033[34m[D]\033[0m"; // Blue for directories
        } else if (S_ISLNK(fileStat.st_mode)) {
            type = "\033[36m[L]\033[0m"; // Cyan for symbolic links
        } else if (fileStat.st_mode & S_IXUSR) {
            type = "\033[32m[X]\033[0m"; // Green for executables
        } else {
            type = "\033[0m[F]\033[0m"; // Reset color for regular files
        }

        // Display based on flags
        if (show_all && show_details) {
            printf("%s %ld %s\n", type, fileStat.st_size, entry->d_name);
        } else if (show_all) {
            printf("%s\n", entry->d_name);
        } else if (show_details) {
            printf("%s %ld %s\n", type, fileStat.st_size, entry->d_name);
        } else {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}
