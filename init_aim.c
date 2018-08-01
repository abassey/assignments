/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
init_aim.c file
*/

#include "aim.h"

int main ()
{
  FILE *students, *courses, *student_course;
  students = fopen("students.bin","wb");
  courses = fopen("courses.bin","wb");
  student_course = fopen("student_course.bin","wb");
  fclose(students);
  fclose(courses);
  fclose(student_course);
  return 0;
}
