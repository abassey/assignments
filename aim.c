#include "aim.h"

int compar_id( const void *a, const void *b )
{
  const struct student_struct *struct_a, *struct_b;

  struct_a = a;
  struct_b = b;

  return ((struct_b->id)-(struct_a->id));
}

struct student_struct *get_student_info(int student_id)
{
  int n1, n2, mid;
  struct student_struct *found_student;
  FILE *fp;
  fp = fopen("students.bin", "rb");

  found_student = malloc(sizeof(struct student_struct));
  n1 = 0;
  fseek(fp, 0, SEEK_END);
  n2 = ftell(fp) / 260;
  fseek(fp, 0, SEEK_SET);

  while (n1 != n2)
  {
    mid = (n1 + n2) / 2;
    fseek(fp, mid * sizeof(struct student_struct), SEEK_SET);
    fread(found_student, 1, sizeof(struct student_struct), fp);

    if(student_id == found_student->id)
      {
        /*printf("first match\n");*/
        return found_student;
    } else if (student_id < found_student->id) {
       /*printf("n2 used\n");*/
        n2 = mid;
    } else if (student_id > found_student->id) {
        /*printf("n1 used\n");*/
        n1 = mid;
    } else {
        /*printf("fnot there at all\n");*/
        free(found_student);
        return NULL;
      }
  }
  fclose(fp);
  return found_student;
}

struct student_course_struct *get_student_course_info(int student_id, char *term)
{
  FILE *fp;
  struct student_course_struct *courses_found;

  courses_found = malloc(sizeof(struct student_course_struct));
  fp = fopen("student_course.bin","rb");

  printf("ID: %d\n", courses_found->student_id);
  printf("entered ID: %d\n", student_id);

  while(!(feof(fp)))
  {
    printf("before if\n");
    printf("ID: %d\n", courses_found->student_id);
    fread(courses_found, 1, sizeof(struct student_course_struct), fp);

      if((courses_found->student_id == student_id) && (strcmp(courses_found->term,term) == 0))
      {
        printf("Testing start\n");
        printf("R: %s\n", courses_found->registration);
        printf("ID: %d\n", courses_found->student_id);
        printf("CC: %s\n", courses_found->course_code);
        printf("T: %s\n", courses_found->term);
        printf("Testing end\n");
        printf("in if\n");
        return courses_found;
      }
    }

  fclose(fp);
  printf("after if\n");
  printf("ID: %d\n", courses_found->student_id);
  return courses_found;
}
