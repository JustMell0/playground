#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *soucet(int delka, int *poleA, int *poleB) {
  int *poleC = malloc(delka * sizeof(int));
  if (poleC != NULL) {
    for (int i = 0; i < delka; i++) {
      poleC[i] = poleA[i] + poleB[i];
    }
  }
  return poleC;
}

char *konkatenace(char *strA, char *strB) {
  char *strC = malloc((strlen(strA) + strlen(strB) + 1) * sizeof(char));
  if (strC != NULL) {
    for (int i = 0; i < strlen(strA); i++) {
      strC[i] = strA[i];
    }
    for (int i; i < strlen(strB); i++) {
      strC[i + strlen(strB)] = strB[i];
    }
    strC[strlen(strA) + strlen(strB)] = '\0';
  }
  return strC;
}

int main() {
  int poleA[3] = {10, 20, 30};
  int poleB[3] = {40, 50, 60};

  int *poleC = soucet(3, poleA, poleB);
  for (int i = 0; i < 3; i++)
    printf("%d ", poleC[i]);

  char strA[] = "Hello";
  char strB[] = "Ahoj";
  char *strC = konkatenace(strA, strB);
  printf("%s", strC);
  free(strC);
  free(poleC);
  return 0;
}
