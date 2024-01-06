#include "headers.h"
void seek(char *flags, char *search, char *target_directory) {
    int flag_d = 0, flag_f = 0, flag_e = 0;

    if (flags) {
        if (strstr(flags, "-d") != NULL) {
            flag_d = 1;
        }
        if (strstr(flags, "-f") != NULL) {
            flag_f = 1;
        }
        if (strstr(flags, "-e") != NULL) {
            flag_e = 1;
        }
    }

    DIR *dir = opendir(target_directory);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char fullpath[PATH_MAX];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", target_directory, entry->d_name);

        struct stat fileStat;
        if (lstat(fullpath, &fileStat) < 0) {
            perror("lstat");
            continue;
        }

        int is_dir = S_ISDIR(fileStat.st_mode);
        int is_file = S_ISREG(fileStat.st_mode);

        if ((flag_d && is_dir) || (flag_f && is_file) || (!flag_d && !flag_f)) {
            if (strcmp(entry->d_name, search) == 0) {
                printf("./%s\n", entry->d_name);
                if (flag_e) {
                    if (is_dir) {
                        if (chdir(fullpath) != 0) {
                            perror("chdir");
                        }
                    } else if (is_file) {
                        FILE *fp = fopen(fullpath, "r");
                        if (fp) {
                            char buffer[1000];
                            while (fgets(buffer, sizeof(buffer), fp)) {
                                printf("%s", buffer);
                            }
                            fclose(fp);
                        } else {
                            perror("fopen");
                        }
                    }
                }
            }
        }
    }
    closedir(dir);
    if (!flag_d && !flag_f && flag_e) {
        printf("Missing permissions for task!\n");
    }
    if (!flag_d && !flag_f && !flag_e) {
        printf("No match found!\n");
    }
}
