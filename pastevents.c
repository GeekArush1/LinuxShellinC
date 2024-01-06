#include"headers.h"
void add_to_pastevents(char *event){
	if(pastevents_count>0 && strcmp(event,pastevents[pastevents_count-1])==0){
		return;
	}
	strcpy(pastevents[pastevents_count],event);
	pastevents_count=(pastevents_count+1)%MAX_HISTORY;
}
void display_pastevents() {
    for (int i = 0; i < pastevents_count; i++) {
        if (strcmp(pastevents[i], "pastevents") == 0) {
            continue;
        }
        else if(pastevents[i]==pastevents[i+1]){
            continue;
        }
        else if((execute_pastevents(i))==1){
            continue;
        }
        else{
            printf("%s",pastevents[i]);
        }
    }
}
int execute_pastevents(int index){
	if(index<=0 || index>pastevents_count){
		printf("Invalid Index\n");
		return 1;
	}
	char **args=tokenize(pastevents[index-1]);
	int no_args=0;
	while(args[no_args]!=NULL){
		no_args++;
	}
	run(args,no_args);
}
