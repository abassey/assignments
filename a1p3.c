/* a1p3.c
By: Anemmeabasi Bassey (abassey@uoguelph.ca)
Student ID: 1032523 */
#include "tictactoe.h"

int main (int argc, char **argv){
  unsigned short w;
  int moveNum;
  char b3[10];
  FILE *fp;
  struct strategy_struct r;
  moveNum = atoi(argv[1]);
  fp = fopen("strategyfile.bin", "rb+");

  for(w = 0; w < 19683; ++w){
    b3fromus(b3,w);
    if(get_move(b3) == moveNum + '0'){
      if(winner(w) == '1' || winner(w) == '2' || winner(w) == '0'){
        r.best_move = -1;
        r.winner = winner(w);
        set_record(fp,w,r);
      } else {
        evaluate_move(w,&r);
        set_record(fp,w,r);
      }
    }
  }
  printf("\n");
  fclose(fp);
  return 0;
}
