/* a1p1.c
By: Anemmeabasi Bassey (abassey@uoguelph.ca)
Student ID: 1032523 */
#include <stdio.h>
#include "tictactoe.h"

int main (int argc, char **argv){
  unsigned short us;
  char b3[10];
  char board[60];
  int s;
  us = atoi(argv[1]);
  b3fromus(b3,us);
  us = b3tous(b3);
  printf("Board number: %d\n", us);
  printf("Board b3: %s\n", b3);
  printf("Board pic: \n");
  boardfromb3(board,b3);
  printf("%s\n", board);
  boardtob3(b3,board);
  printf("b3: %s\n", b3);
  printf("Move: %c\n", get_move(b3));
  printf("Turn: %c\n", get_turn(b3));
  printf("Winner: %c\n", winner(us));
  for(s = 0; s <= 8; ++s){
    printf("%d -> %d \n", s,next(us, (s + '0')));
  }
  printf("\n");
  return 0;

}
