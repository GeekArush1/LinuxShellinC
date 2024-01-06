#ifndef HEADERS_H_
#define HEADERS_H_

#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<limits.h> 
#include <pwd.h> 
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/stat.h>
#include <dirent.h>
#include<time.h>
#include<math.h>
#define MAX_HISTORY 15
extern char pastevents[MAX_HISTORY][2000];
extern int pastevents_count;
extern int n;
extern char HOME_DIRECTORY[PATH_MAX];
void init_shell();
char *get_input();
void number(char *input);
char **tokenize(char *input);
void removeSpaces(char *str);
void run(char **args, int no_args);
void warp(char *command);
void peek(char *flags, char *path);
void add_to_pastevents(char *event);
void display_pastevents();
int execute_pastevents(int index);
void seek(char *flags, char *search, char *target_directory);
void proclore(char *pid_str);
void execute_com(char *command);
#endif
