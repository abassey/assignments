/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
grade.c file
*/

#include "aim.h"
int main (int argc, char **argv)
{
  char *filename;
  FILE *fp;

  filename = argv[1];
  fp = fopen(filename, "r");
  /*
  struct student_struct *student_to_update;
  student_to_update = malloc(sizeof(struct student_struct));
  student_to_update = get_student_info();
  */

  fclose(fp);
  return 0;
}
