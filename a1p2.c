/* a1p2.c
By: Anemmeabasi Bassey (abassey@uoguelph.ca)
Student ID: 1032523 */
#include "tictactoe.h"

int main (int argc, char **argv){
  int i;
  FILE *fp;
  struct strategy_struct strategy;
  strategy.best_move = -1;
  strategy.winner = ' ';
  fp = fopen("strategyfile.bin", "wb");
  for (i = 0; i < 19683; ++i){
    fwrite(&strategy, sizeof(struct strategy_struct), 1, fp);
  }
  fclose(fp);
  return 0;
}
