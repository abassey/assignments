#include <stdio.h>
#include <stdlib.h>
int main (){
  void *ptr;
  ptr = malloc(10);
  free(NULL);

  return 0;
}
