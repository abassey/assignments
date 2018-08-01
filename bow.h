/*
Name: Anemmeabasi Bassey, 1032523
Email: abassey@uoguelph.ca
Course: CIS*2500
Header file
*/
#ifndef BOW_H
#define BOW_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct word_count_struct {
  char *word;
  int   count;
};

struct bag_struct {
  struct word_count_struct *bag;
  int bag_size;
  int total_words;
};

struct bag_struct *new_bag();
int bagsearch( struct bag_struct *bow, char *word );
char *get_word( char **string_ptr );
struct word_count_struct *new_word_count( char *word );
void add_word( struct bag_struct *bow, char *word );
void add_text( struct bag_struct *bow, char *line );
void read_sms_data( struct bag_struct *bow, char *label );
void differences( struct bag_struct *ham, struct bag_struct *spam );
int is_letter(char character);
void print_word_count(struct word_count_struct *word);
void print_bag(struct bag_struct *current_bag);
void free_bag(struct bag_struct *current_bag);
#endif
