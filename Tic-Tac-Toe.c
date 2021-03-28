#include<stdio.h>
#include<string.h>

typedef enum {FALSE, TRUE} BOOL;

char table[3][3] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
};
  BOOL isRunning = TRUE;


void printTable(char arr[3][3]) {
  //printf("-------------");
  printf("\n");
  for(int i=0; i<3; i++){
    //printf("|");
    for(int j=0; j<3; j++){
      printf(" %c ", arr[i][j]);
    }
    printf("\n");
    //printf("-------------");
    printf("\n");
  }
}


int count=0;
char player[10];

void mark(int pos, char move) {
  move = count%2 == 0 ? 'o' : 'x';
  switch(pos){
    case 1: {
              if(table[0][0]!='x' && table[0][0]!='o'){
              count++;
              table[0][0] = move ;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 2: {
              if(table[0][1]!='x' && table[0][1]!='o'){
              count++;
              table[0][1] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 3: {
              if(table[0][2]!='x' && table[0][2]!='o'){
              count++;
              table[0][2] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 4: {
              if(table[1][0]!='x' && table[1][0]!='o'){
              count++;
              table[1][0] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 5: {
              if(table[1][1]!='x' && table[1][1]!='o'){
              count++;
              table[1][1] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 6: {
              if(table[1][2]!='x' && table[1][2]!='o'){
              count++;
              table[1][2] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 7: {
              if(table[2][0]!='x' && table[2][0]!='o'){
              count++;
              table[2][0] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 8: {
              if(table[2][1]!='x' && table[2][1]!='o'){
              count++;
              table[2][1] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
    case 9: {
              if(table[2][2]!='x' && table[2][2]!='o'){
              count++;
              table[2][2] = move;
              } else {printf("Wrong block, try again\n");}
              break;
            }
  }
}

void checkCondition(){
  
  for(int i=0; i<3; i++){
    if (//rows
        table[i][0]==table[i][1] &&
        table[i][1]==table[i][2]
        ) { 
      system("clear");
      printTable(table);
    
      if(table[i][0]=='o')
        printf("Player 1 wins\n");
      else 
        printf("Player 2 wins\n");
      
      isRunning=FALSE;
      break;
    }
    else if(//columns
          table[0][i]==table[1][i] &&
          table[1][i]==table[2][i]
            ){
      system("clear");
      printTable(table);
      if(table[i][0]=='o')
        printf("Player 1 wins\n");
      else 
        printf("Player 2 wins\n");
      isRunning=FALSE;
      break;
    } 
    else if(//diagonals
          (table[0][0]==table[1][1] &&
          table[1][1]==table[2][2])||
          (table[0][2]==table[1][1] &&
          table[1][1]==table[2][0])
              ){
      system("clear");
      printTable(table);
      if(table[i][0]=='o')
        printf("Player 1 wins\n");
      else 
        printf("Player 2 wins\n");
      isRunning=FALSE;
      break;
    }

    else {
        system("clear");
        printTable(table);
    }
  }
}

void checkDraw () {
      BOOL isDraw = TRUE;
      for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
          if (table[i][j]>='1' && table[i][j]<='9'){
            isDraw = FALSE;
          }
        }
      }
      if (isDraw){
        system("clear");
        printTable(table);
        printf("It's a Draw\n");
        exit(0);
      } else {
        system("clear");
        printTable(table);
      }
}

int main() {
  int block;
  do {
   
    count%2==0 ? strcpy(player, "Player 1") : strcpy(player, "Player 2");
    system("clear");
    printTable(table);
    checkDraw();
    printf("%s, Choose your block: ", player);
    scanf("%d", &block);
    mark(block, 'x');
    checkCondition();

  }while(isRunning);
  
  return 0;
}

/*
   1  2  3
   4  5  6
   7  8  9
*/
