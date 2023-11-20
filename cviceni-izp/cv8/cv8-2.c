#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int* pole = malloc(3);
  for (int i = 0; i < 3; i++){
    scanf("%d", &pole[i]);
  }
  bool rostouci = true;
  for (int i = 0; i < 3; i++){
    if (pole[i] > pole[i + 1]){
      rostouci = false;
    }
  }
  if (rostouci){
    printf("JE Rostouci\n");
  } else {
    printf("NENI rostouci\n");
  }
}
