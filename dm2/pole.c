#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *p;
  int size;
  int cap;
}Array;

void array_ctor (Array *a) {
  a->p = NULL;
  a->size = 0;
  a->cap = 0;
}

void array_print(Array *a){
  for (int i = 0; i < a->size; i++) {
    putchar(a->p[i]);
  }
  putchar('\n');
}

int array_append(Array *a, char data){
  if (a->size < a->cap)
    a->p[a->size] = data;
  else {
    char *ptr = realloc(a->p, a->cap + sizeof(char));
    if (ptr == NULL)
      return -1;
    a->p = ptr;
    a->cap++;
  }
  return 0;
}

void array_free(Array *a){
  if (a->p != NULL){
    free (a->p);
    a->size = 0;
    a->cap = 0;
  }
}

void array_dtor(Array *a){
  if (a->p != NULL)
    free(a->p);
}

int main (int argc, char *argv[]) {
  Array a;
  array_ctor(&a);
  
  int err = 0;
  err += array_append(&a, 'H');
  err += array_append(&a, 'e');
  err += array_append(&a, 'l');
  err += array_append(&a, 'l');

  array_print(&a);

  array_dtor(&a);
  return 0;
}
