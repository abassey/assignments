/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
register.c file
*/

#include "aim.h"

 int main ()
 {
   FILE *fp;
   struct student_struct new_student;

   int max_id = 0;

   fp = fopen("students.bin", "rb+");

   new_student.id = 0;

   while(!(feof(fp)))
   {
     fread(&new_student, 1, sizeof(struct student_struct), fp);

     if (new_student.id > max_id)
     {
       max_id = new_student.id;
     }
   }

   printf("Last name: ");
   scanf("%s", new_student.last_name);
   printf("First name: ");
   scanf("%s", new_student.first_name);
   printf("Middle name: ");
   scanf("%s", new_student.middle_names);
   printf("Major: ");
   scanf("%s", new_student.major);

   new_student.id = max_id + 1;

   fseek(fp, sizeof(struct student_struct), SEEK_END);
   fwrite(&new_student, 1, sizeof(struct student_struct), fp);


   fclose(fp);

   /* Testing Suites

   printf("Testing start\n");
   printf("Last Name: %s\n", new_student.last_name);
   printf("First Name: %s\n", new_student.first_name);
   printf("Midlle Name: %s\n", new_student.middle_names);
   printf("Major: %s\n", new_student.major);
   printf("ID: %d\n", new_student.id);
   printf("Testing end\n");
   */

   return 0;
 }
