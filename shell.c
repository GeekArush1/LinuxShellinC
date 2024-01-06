#include"headers.h"
void shell() {
    char *input;
    do
    {
        init_shell();
        input = get_input();
        char **commands;
        commands = tokenize(input);
        for(int i = 0; i <= n; i++){
            	execute_com(commands[i]);
            }
    } while(1);
}
