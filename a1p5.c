#include "tictactoe.h"

int main () {
  char userName[20];
  FILE *fp;
  struct strategy_struct moveFind;
  char b3[10] = "0";
  char board[60];
  unsigned short i;
  char userSide;
  char progSide;
  char userMove;
  char progMove;

  fp = fopen("strategyfile.bin", "rb");
  i = 0;
  printf("SHALL WE PLAY A GAME?\n\n");
  printf("PLEASE ENTER YOUR NAME: ");
  scanf("%s", userName);
  printf("\n");
  printf("GREETINGS %s\n", userName);
  printf("Which side would you like to play (X/O)?   ");
  scanf(" %c", &userSide);
  printf("\n");
  if (userSide == 'X'){
    progSide = 'O';
    printf("Ok, you will be %c, I will be %c.\n\n", userSide, progSide);
  } else if (userSide == 'O'){
    progSide = 'X';
    printf("Ok, you will be %c, I will be %c.\n\n", userSide, progSide);
  }

  while (winner(i) != '0' || winner(i) != '1' || winner(i) != '2'){
    b3fromus(b3,i);
    boardfromb3(board, b3);
    printf("%s\n\n", board);
    get_record(fp,i,&moveFind);
    progMove = moveFind.best_move;
    printf("My turn; my move is %c: \n\n", progMove);
    boardfromb3(board, b3);
    boardtob3(b3, board);
    printf("%s\n\n", board);
    printf("Your turn; chose a move [0-8]:  ");
    scanf(" %c", &userMove);
    i = next(i,(get_move(b3)));
    b3fromus(b3, i);
    boardfromb3(board, b3);
    boardtob3(b3, board);
    printf("\n");

  }

  fclose(fp);
  return 0;
}
