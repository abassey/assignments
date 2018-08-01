/*
Anemmeabasi Bassey
1032523
CIS2500 Assignment 4
sort.c file
*/

#include "aim.h"

int main ()
{
  FILE *fp;
  struct student_struct *student_array;
  long int size = 0;
  int num_records = 0;

  fp = fopen("students.bin", "rb");

  fseek(fp, sizeof(struct student_struct), SEEK_END);
  size = ftell(fp);
  /*printf("size = %d bytes \n", size);*/
  num_records = size / sizeof(struct student_struct); /*this increases by 2 each time. ask if correct*/
  /*printf("num_records = %d\n", num_records);*/

  student_array = calloc(num_records, sizeof(struct student_struct));
  fread(&student_array, 1, sizeof(struct student_struct), fp);
  qsort(student_array, sizeof(student_array), sizeof(struct student_struct), compar_id);/*ask if the second argument is correct*/
  fclose(fp);

  fp = fopen("students.bin", "wb");
  fwrite(&student_array, 1, sizeof(struct student_struct), fp);
  free(student_array);
  fclose(fp);

  return 0;
}
