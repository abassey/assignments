/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
class_list.c file
*/

#include "aim.h"
int main (int argc, char **argv)
{
  char *entered_course_code;
  char *entered_term;
  char *filename;
  FILE *fp;

  entered_course_code = argv[1];
  entered_term = argv[2];
  filename = argv[3];

  fp = fopen(filename, "w");

  fclose(fp);
  return 0;
}
