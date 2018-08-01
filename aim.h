#ifndef AIM_H
#define AIM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student_struct {
     char last_name[64];
     char first_name[64];
     char middle_names[64];
     int id;
     char major[64];
};

struct course_struct {
     char code[10];
     char term[6];
     char title[128];
     char instructor[64];
};

struct student_course_struct {
     int student_id;
     char course_code[10];
     char term[6];
     char registration[4];
     int grade;
};

struct linked_list_struct {
    struct student_course_struct current;
    struct student_course_struct *next;
};

int compar_id( const void *a, const void *b );
struct student_struct *get_student_info(int student_id);
struct student_course_struct *get_student_course_info(int student_id, char *term);

#endif
