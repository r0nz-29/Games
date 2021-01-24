#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define UPPER 2
#define LOWER 0
void dropWhites(char str[]){
	char *p = strchr(str, '\n');
	if(p != NULL){
		*p = '\0';
	}
}
int main(){
	char moves[3][8] = {"rock", "paper", "scissors"};
	int flag = 1;
	int score = 0;
	printf("(Input * to exit)\n");
	do {
		int rand_index = rand()%(UPPER-LOWER+1)+LOWER;
		char usr_input[10];
		char comp_move[10];
		//printf("%d\n", rand_index);
		strcpy(comp_move, moves[rand_index]);
		dropWhites(comp_move);
		printf(">> ");
		fgets(usr_input, 10, stdin);
		dropWhites(usr_input);
		//puts(comp_move);
		//comparing:
		if(usr_input[0] == '*'){
			flag = 0;
			printf("Your Score: %d\n", score);
		}
		if(strcmp(usr_input, "rock")==0){//start
			if(strcmp(comp_move, "paper")==0){
				printf("Comp's move: %s\n", comp_move);
				printf("You loose\n");
				score-=1;
			}
			else if(strcmp(comp_move, "scissors")==0){
				printf("Comp's move: %s\n", comp_move);
				printf("You Win!\n");
				score+=10;
			} else {
				printf("Comp's move: %s\n", comp_move);
				printf("Draw\n");
			}
		}//end
		if(strcmp(usr_input, "paper")==0){//start
			if(strcmp(comp_move, "scissors")==0){
				printf("Comp's move: %s\n", comp_move);
				printf("You loose\n");
				score-=1;
			}
			else if(strcmp(comp_move, "rock")==0){
				printf("Comp's move: %s\n", comp_move);
				printf("You Win!\n");
				score+=10;
			} else {
				printf("Comp's move: %s\n", comp_move);
				printf("Draw\n");
			}
		}//end
		if(strcmp(usr_input, "scissors")==0){//start
			if(strcmp(comp_move, "rock")==0){
				printf("Comp's move: %s\n", comp_move);
				printf("You loose\n");
				score-=1;
			}
			else if(strcmp(comp_move, "paper")==0){
				printf("Comp's move: %s\n", comp_move);
				printf("You Win!\n");
				score+=10;
			} else {
				printf("Comp's move: %s\n", comp_move);
				printf("Draw\n");
			}
		}//end
	} while(flag);
	return 0;
}
