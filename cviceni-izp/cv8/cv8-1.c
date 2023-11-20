#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){

  if(argc < 3){
    fprintf(stderr, "Chyba\n");
    return 1;
  }
  
  int radek = atoi(argv[1]);
  int sloupec = atoi(argv[2]);

  char *pole = malloc(radek * sloupec * sizeof(char));

  if (pole == NULL){
    fprintf(stderr, "Chyba\n");
    return 2;
  }

  scanf("%s", pole);

  if (strlen(pole) != radek * sloupec){
    fprintf(stderr, "Chyba\n");
    return 3;
  }

  for (int i = radek - 1; i >= 0; i--){
    for (int j = 0; j < sloupec; j++){
      printf("%c", pole[i * sloupec + j]);
    }
    printf("\n");
  }

  free(pole);

  return 0;
}
