#include <stdio.h>
#include <stdlib.h>

int main(){
  int* a = malloc(1048576);
  int size = 1;

  while (a != NULL){
    printf("Alokace %d MiB uspela\n", size);
    a = malloc(1048576 * size);
    size++;
    free(a);
  }
  printf("Alokace %d MiB neuspela\n", size);
  free (a);
  return 0;
}
