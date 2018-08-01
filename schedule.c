/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
schedule.c file
*/

#include "aim.h"

 int main ()
 {
   FILE *fp;
   struct course_struct new_course;


   printf("Code: ");
   scanf("%s", new_course.code);
   printf("Term: ");
   scanf("%s", new_course.term);
   printf("Title: ");
   scanf("%s", new_course.title);
   printf("Instructor: ");
   scanf("%s", new_course.instructor);

   fp = fopen("courses.bin", "ab");

   /*fseek(fp, sizeof(struct course_struct), SEEK_END);*/
   fwrite(&new_course, 1, sizeof(struct course_struct), fp);

   fclose(fp);
   return 0;
 }
