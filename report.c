/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
report.c file
*/
#include "aim.h"
int main (int argc, char **argv)
{
  struct student_course_struct *courses_found;

  int entered_id;
  char term[6];

  entered_id = atoi(argv[1]);
  strcpy(term,argv[2]);
  courses_found = malloc(sizeof(struct student_course_struct));
  courses_found = get_student_course_info(entered_id,term);
  /* Testing Suites
  printf("cc: %s\n", courses_found->course_code);
  */
  return 0;
}
