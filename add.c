/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
add.c file
*/

#include "aim.h"

 int main ()
 {
   FILE *fp;
   struct student_course_struct new_member;

   printf("Student ID: ");
   scanf("%d", &new_member.student_id);
   printf("Course Code: ");
   scanf("%s", new_member.course_code);
   printf("Term: ");
   scanf("%s", new_member.term);

   do{
     printf("Resgistration [CRD or AUD]: ");
      scanf("%s", new_member.registration);
  }while(!(strcmp(new_member.registration,"CRD") == 0 || strcmp(new_member.registration,"AUD") == 0)); /*ask if this logic is correct*/

   new_member.grade = -1;
   fp = fopen("student_course.bin", "ab");

   /*fseek(fp, sizeof(struct student_course_struct), SEEK_END);*/
   fwrite(&new_member, 1, sizeof(struct student_course_struct), fp);

   fclose(fp);

   /* Testing Suites

   printf("Testing start\n");
   printf("R: %s\n", new_member.registration);
   printf("ID: %d\n", new_member.student_id);
   printf("CC: %s\n", new_member.course_code);
   printf("T: %s\n", new_member.term);
   printf("Testing end\n");

   */
   return 0;
 }
