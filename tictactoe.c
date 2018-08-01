/* tictactoe.c
By: Anemmeabasi Bassey (abassey@uoguelph.ca)
Student ID: 1032523 */
#include "tictactoe.h"

unsigned short b3tous(char b3[10]){
  char b3cpy[10];
  unsigned short us = 0;
  int val = 1;
  int j;

  for (j = 8; j >= 0; --j){
    b3cpy[j] = b3[j];
    b3cpy[j] = b3cpy[j] - '0';
    us = us + (b3cpy[j] * val);
    val = val * 3;
  }

  return us;
}

void b3fromus( char b3[10], unsigned short us ){
  int i;
  b3[9] = '\0';
  for (i = 8; i >= 0; --i){
    b3[i] = '0' + us%3;
    us = us / 3;
  }
}


void boardfromb3(char board[60], char b3[10]){
  int h, index;
  strcpy(board, "   |   |   \n---+---+---\n   |   |   \n---+---+---\n   |   |   \0");
  for (h = 0; h <= 8; ++h){
    index = 4 * h + 1;
    index = index + ((h / 3) * 12);
    board[index] = '?';

    switch (b3[h]){
      case '2':
        board[index] = 'X';
        break;
      case '1':
        board[index] = 'O';
        break;
      case '0':
        board[index] = ' ';
        break;
      default:
        fprintf( stderr, "Error: bad value in b3\n" );
        exit(-1);
        break;
    }
  }
}

void boardtob3(char b3[10], char board[60]){
  int h, index;
  for (h = 0; h <= 8; ++h){
    index = 4 * h + 1;
    index = index + ((h / 3) * 12);

    switch (board[index]){
      case 'X':
        b3[h] = '2';
        break;
      case 'O':
        b3[h] = '1';
        break;
      case ' ':
        b3[h] = '0';
        break;
      default:
        fprintf( stderr, "Error: bad value in b3\n" );
        exit(-1);
        break;
    }
  }
}

char get_move(char b3[10]){
  int g;
  int move = 0;
  char moveC;
  for(g = 0; g <= 8; ++g){
    if(b3[g] != '0'){
        move += 1;
    }
  }
  moveC = move + '0';
  return moveC;
}

char get_turn(char b3[10]){
  int f;
  int t;
  char turn;
  t = get_move(b3) + '0';
  for (f = 0; f <= 8; ++f){
    if(t % 2 == 0){
      turn = '2';
    } else {
        turn = '1';
    }
  }
  return turn;
}

char winner(unsigned short us){
  char b3w[10];
  b3fromus(b3w,us);
  /*horizontal win cases. NOTE: ONLY ONE CASE SEEMS TO BE WORKING */
  if (b3w[6] == '2' && b3w[7] == '2' && b3w[8] == '2'){
    return '2';
  } else if (b3w[6] == '1' && b3w[7] == '1' && b3w[8] == '1'){
    return '1';
  } else if (b3w[3] == '2' && b3w[4] == '2' && b3w[5] == '2'){
    return '2';
  } else if (b3w[3] == '1' && b3w[4] == '1' && b3w[5] == '1'){
    return '1';
  } else if (b3w[0] == '2' && b3w[1] == '2' && b3w[2] == '2'){
    return '2';
  }else if (b3w[0] == '1' && b3w[1] == '1' && b3w[2] == '1'){
    return '2';
  }

  /*vertical win cases*/ else if (b3w[0] == '2' && b3w[3] == '2' && b3w[6] == '2'){
    return '2';
  }else if (b3w[0] == '1' && b3w[3] == '1' && b3w[6] == '1'){
    return '1';
  }else if (b3w[1] == '2' && b3w[4] == '2' && b3w[7] == '2'){
    return '2';
  }else if (b3w[1] == '1' && b3w[4] == '1' && b3w[7] == '1'){
    return '1';
  }else if (b3w[2] == '2' && b3w[5] == '2' && b3w[8] == '2'){
    return '2';
  }else if (b3w[2] == '1' && b3w[5] == '1' && b3w[8] == '1'){
    return '2';
  }
/*diagonal win cases*/else if (b3w[0] == '2' && b3w[4] == '2' && b3w[8] == '2'){
    return '2';
  }else if (b3w[0] == '1' && b3w[4] == '1' && b3w[8] == '1'){
    return '2';
  }else if (b3w[2] == '2' && b3w[4] == '2' && b3w[6] == '2'){
    return '2';
  }else if (b3w[2] == '1' && b3w[4] == '1' && b3w[6] == '1'){
    return '2';
  }else if (b3w[0]!='0'&& b3w[1]!='0'&& b3w[2]!='0'&& b3w[3]!='0'&& b3w[4]!='0'&& b3w[5]!='0'&& b3w[6]!='0'&& b3w[7]!='0'&& b3w[8]!='0'){
    return '0';
  }
 return ' ';
}

unsigned short next (unsigned short us, char pos){
  char b3n[10];
  int n;
  char turn;
  n = pos - '0';
  b3fromus(b3n,us);
  turn = get_turn(b3n);

    if(b3n[n] != '0'){
      return 0;
    } else if(turn == '2' && b3n[n] == '0'){
      b3n[n] = turn;
      us = b3tous(b3n);
      return us;
    }  else if(turn == '1' && b3n[n] == '0'){
      b3n[n] = turn;
      us = b3tous(b3n);
      return us;
    }

  return us;
}

void get_record( FILE *fp, unsigned short us, struct strategy_struct *record ){

   fseek(fp,sizeof(struct strategy_struct)*us, SEEK_SET);
   fread(record,sizeof(struct strategy_struct), 1, fp);
}

void set_record( FILE *fp, unsigned short us, struct strategy_struct record ){
   fseek(fp,sizeof(struct strategy_struct)*us, SEEK_SET);
   fwrite(&record,sizeof(struct strategy_struct), 1, fp);
}

void evaluate_move(unsigned short us, struct strategy_struct *record){
  FILE *fp;
  int e;
  unsigned short boardCheck;
  struct strategy_struct winnerCheck;
  char b3e[10];
  char winTurn;
  char winStr;
  int found_tie = 0;
  int legal_move = 0;
  int tempPoint = 0;


  fp = fopen("strategyfile.bin", "rb+");
  for (e = 0; e <= 8; ++e){
    b3fromus(b3e,us);
    winTurn = get_turn(b3e);
    boardCheck = next(us, b3e[e]);

    if(boardCheck == 0){
      continue;
    } else {
      get_record(fp,us,&winnerCheck);
      winStr = winnerCheck.winner;
      if (winStr == winTurn){
        record->best_move = e;
        record->winner = winStr;
      }

      if (winStr == '0'){
        found_tie = 1;
        tempPoint = e;
      } else {
        legal_move = e;
      }
    }

  }

  if (found_tie == 1){
    record->winner = '0';
    record->best_move = tempPoint;
  } else if (found_tie == 0 && winStr == '1') {
    record->winner = '2';
    record->best_move = legal_move;
  } else {
    record->winner = '1';
    record->best_move = legal_move;
  }
  fclose(fp);
}
