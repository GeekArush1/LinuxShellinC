#include"headers.h"
void execute_com(char *command) {
	char *com2 = (char *)malloc(sizeof(char) *2000);
	char *com = (char *)malloc(sizeof(char) *2000);
	char *com3= (char *)malloc(sizeof(char) *2000);
	strcpy(com2, command);
	strcpy(com, command);
	strcpy(com3, command);
	removeSpaces(com2);
	if(com == NULL){
		return;
	}
	add_to_pastevents(com3);
    char *token=strtok(com, " \n\t\r");
	char *args[100];
    int no_args = 0;
	while (token != NULL)
	    {
		args[no_args]=strdup(token);
        // printf("%s\n",args[no_args]);
		no_args++;
        token = strtok(NULL, " \n\t\r");
	    }
    args[no_args] = malloc(sizeof(char)*100);
    args[no_args++] = NULL; 
    command=strtok(command," \n\t\r");
    // printf("Hi All");
    int is_background = 0;
    int len = strlen(args[no_args - 2]);
        int i=0;
        while(len!=0){
            if (com2[i]=='&') {
         args[no_args - 2][len - 1] = '\0'; // Remove the '&' character
            is_background = 1;
            break;
        }
            else{
            	len--;
            	i++;
            }
      }
    if (strcmp(command, "warp") == 0) {
        warp(com2);
    }
    else if (strcmp(command, "peek") == 0) {
        char *flags = strtok(NULL, " \n\t\r");
        char *path = strtok(NULL, " \n\t\r");
        if (!path) {
            // Use the current working directory as the default path
            if (getcwd(path, sizeof(path)) == NULL) {
                perror("getcwd");
                return;
            }
        }
        peek(flags, path);
    } 
    else if(strcmp(command,"pastevents")==0){
    	char *subcommand=strtok(NULL," \n\t\r");
    	printf("%s",subcommand); 
    	if(subcommand){
    		if(strcmp(subcommand,"execute")==0){
    			int index=atoi(strtok(NULL," \n\t\r"));
    			execute_pastevents(index);
    		}
    	}
    	else{
    		display_pastevents();	
    	}
    }
    else if(strcmp(command,"seek")==0){
    	char *flags=strtok(NULL," \n\t\r");
    	char *search=strtok(NULL," \n\t\r");
    	char *target_directory=strtok(NULL, " \n\t\r");
    	if(!search){
    		printf("Missing search parameter!\n");
    		return;
    	}
    	else if(!target_directory){
    		target_directory=".";
    	}
    	seek(flags,search,target_directory);
    }
    else if(strcmp(command,"proclore")==0){
    	char *pid_str=strtok(NULL," \n\t\r");
    	proclore(pid_str);
    }
    else if (is_background){
            pid_t pid = fork();
            if (pid == 0) {
                // Child process (background)
                run(args, no_args - 1); // Exclude the '&' argument
                exit(0);
            } else if (pid > 0) {
                // Parent process (shell)
                printf("[%d]\n", pid);
            } else {
                perror("fork");
            }
        
            // Foreground process
            struct timespec start_time, end_time;
            clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);
            run(args, no_args);
            clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);

            double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                                  (end_time.tv_nsec - start_time.tv_nsec) * 1e-9;

            if (elapsed_time > 2) {
                printf("%s : %.0fs\n", args[0], (elapsed_time));
            }
	}
    else{
        run(args,no_args);
    }
    for (int i = 0; i <= no_args; i++) {
        // free(args[i]);
    }
    // free(args);
}
