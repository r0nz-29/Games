#include<stdio.h>
#include<stdlib.h>
#define UPPER 10
#define LOWER 1
#define TRUE 1
#define FALSE 0
int main(){
  int flag = TRUE;
  int comp_num; 
  int usr_num;
  int tries=1;
  printf("Your computer just thought of a number b/w 1 and 10(inclusive ofc),\n");
  srand(time(NULL));
  do{
  comp_num = rand()%(UPPER-LOWER+1)+LOWER;//comp decides a num
  printf("Guess the number: \n ");
  scanf("%d", &usr_num);
    
  if(usr_num==0){
    flag = FALSE;
  } else {
    if(usr_num==comp_num) {
      printf("Correct !\n");
      flag = FALSE;
    } 
    else if(usr_num>comp_num) {
      printf("Too big\n");tries++;
    } else {
        printf("Too small\n");tries++;
    }
  }
  
  }while(flag);
  printf("Hehe, took %d trials to guess correctly\n", tries);
  return 0;
}
