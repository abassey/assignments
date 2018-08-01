/* tictactoe.h
Header file
By: Anemmeabasi Bassey (abassey@uoguelph.ca)
Student ID: 1032523 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned short b3tous(char b3[10]);
void b3fromus(char b3[10], unsigned short us);
void boardfromb3(char board[60], char b3[10]);
void boardtob3(char b3[10], char board[60]);
char winner(unsigned short us);
char get_move(char b3[10]);
char get_turn(char b3[10]);
unsigned short next (unsigned short us, char pos);
struct strategy_struct
{
    char best_move;
    char winner;
};
void get_record( FILE *fp, unsigned short us, struct strategy_struct *record );
void set_record( FILE *fp, unsigned short us, struct strategy_struct record );
void evaluate_move(unsigned short us, struct strategy_struct *record);
