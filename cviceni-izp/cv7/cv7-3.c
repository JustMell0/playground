#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Smnozina{
  int delka;
  int *pole;
} mnozina;

mnozina* alokuj(int delka) {
  mnozina* m = malloc(sizeof(mnozina));
  m->delka = delka;
  m->pole = malloc(delka * sizeof(int));
  return m;
}

void nactiMnozinu(mnozina* A) {
  for (int i = 0; i < A->delka; i++) {
    scanf("%d", &A->pole[i]);
  }
}

void vypisMnozinu(mnozina* A) {
  for (int i = 0; i < A->delka; i++) {
    printf("%d ", A->pole[i]);
  }
  printf("\n");
}

void uvolniMnozinu(mnozina* A){
  free(A->pole);
  free(A);
}

bool jeMnozina(mnozina* A){
  for (int i = 0; i < A->delka; i++) {
    for (int j = i + 1; j < A->delka; j++) {
      if (A->pole[i] == A->pole[j]) {
        return false;
      }
    }
  }
  return true;
}

mnozina* konkatenaceMnozin(mnozina* A, mnozina* B){
  mnozina* C = alokuj(A->delka + B->delka);
  for (int i = 0; i < A->delka; i++){
    C->pole[i] = A->pole[i];
  }
  for (int i = 0; i < B->delka; i++){
    C->pole[i + B->delka + 1] = B->pole[i];
  }
  return C;
}

mnozina* prunikMnozin(mnozina* A, mnozina* B){
  mnozina* C = alokuj(A->delka + B->delka);
  int cnt = 0;
  for (int i = 0; i < A->delka; i++){
    for (int j = 0; i< B->delka; j++){
      if (A->pole[i] == B->pole[j]){
        C->pole[cnt] = A->pole[i];
        cnt++;
      }
    }
  }
  return C;
}

int main() {
  mnozina* A = alokuj(4);
  if (A == NULL || A->pole == NULL) return 1;
  nactiMnozinu(A);
  vypisMnozinu(A);

  mnozina* B = alokuj(3);
  if (B == NULL || B->pole == NULL) return 2;
  nactiMnozinu(B);
  vypisMnozinu(B);
  if (!jeMnozina(B) || !jeMnozina(A)) return 3;
  
  mnozina* C = konkatenaceMnozin(A, B);
  if (C == NULL || C->pole == NULL) return 4;
  vypisMnozinu(C);
  uvolniMnozinu(C);

  C = prunikMnozin(A, B);
  if (C == NULL || C->pole == NULL) return 5;
  vypisMnozinu(C);
  uvolniMnozinu(C);
  uvolniMnozinu(B);
  uvolniMnozinu(A);

  return 0;
}
