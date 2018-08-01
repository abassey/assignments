/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
class_schedule.c file
*/

#include "aim.h"

int main (int argc, char **argv)
{
  struct student_struct *student_to_search;
  struct student_course_struct *courses_found;

  int entered_id;
  char term[6];

  entered_id = atoi(argv[1]);
  strcpy(term,argv[2]);
  student_to_search = malloc(sizeof(struct student_struct));
  student_to_search = get_student_info(entered_id);
  courses_found = malloc(sizeof(struct student_course_struct));
  courses_found = get_student_course_info(entered_id,term);
  /* Testing Suites
  printf("id entered: %d\n", entered_id);
  printf("term entered: %s\n", term);
  printf("ln: %s\n",student_to_search->last_name);
  printf("fn: %s\n",student_to_search->first_name);
  printf("mn: %s\n",student_to_search->middle_names);
  printf("m: %s\n",student_to_search->major);
  printf("id: %d\n",student_to_search->id);
  printf("cc: %s\n", courses_found->course_code);*/

  return 0;
}
