/*
Anemmeabasi Bassey, 1032523
abassey@uoguelph.ca
Assignment 3
memcheck.c file
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



struct linked_list_struct
{
  void *memptr;
  char *filename;
  int line_num;
  struct linked_list_struct *next;
};

struct linked_list_struct *first_item = NULL;

void print_list(struct linked_list_struct *ptr)
{
  while(ptr)
  {
    fprintf(stderr, "memcheck error:  memory address %p which was allocated in file \"%s\", line %d, was never freed\n", ptr->memptr, ptr->filename, ptr->line_num);
    ptr = ptr->next;
  }

}

int memcheck_main()
{
  /*print_list(first_item);*/

  return 0;
}



void *memcheck_malloc(size_t size, char *file, int line)
{
  void *tempRtn;
  struct linked_list_struct *new_item;
  tempRtn = malloc(size);
  new_item = malloc(sizeof(struct linked_list_struct));
  new_item->memptr = &tempRtn;
  new_item->filename = strdup(file);
  new_item->line_num = line;
  new_item->next = first_item;
  first_item = new_item;

  return tempRtn;
}


void memcheck_free(void *ptr, char *file, int line)
{
  struct linked_list_struct **double_ptr;
  struct linked_list_struct *temp_ptr;
  double_ptr = &first_item;
  (*double_ptr)->filename = file;
  (*double_ptr)->line_num = line;
  double_ptr = &((*double_ptr)->next);

  while(*double_ptr)
  {
    if((*double_ptr)->memptr == ptr)
    {
        temp_ptr = *double_ptr;
        *double_ptr = temp_ptr->next;
        temp_ptr->next = NULL;
        free(temp_ptr);
        fprintf(stderr, "memcheck error:  attempting to free memory address %p in file \"%s\", line %d.\n", (*double_ptr)->memptr, (*double_ptr)->filename, (*double_ptr)->line_num);
    } else {
        print_list(*double_ptr);
    }
  }
  double_ptr = &((*double_ptr)->next);
}

void *memcheck_calloc(size_t nmemb, size_t size, char *file, int line)
{
  void *ptr;
  int i;

  for(i = 0; i < nmemb; i++)
  {
    ptr = memcheck_malloc(size,file,line);
  }
  return ptr;
}

void *memcheck_realloc(void *ptr, size_t size, char *file, int line)
{
  void *return_ptr;
  return_ptr = ptr;
  memcheck_malloc(size,file,line);
  memcpy(return_ptr,ptr,size);
  memcheck_free(ptr,file,line);
  return return_ptr;
}
