#include <stdio.h>
#include <stdlib.h>


typedef struct {
  int delka;
  char *pole;
} vektor;

void vypisVektor(vektor* A);
void pridejPosledni(vektor* A, int cislo);
void odeberVsechny(vektor* A);
void pridejPrvni(vektor* A, int cislo);
void odeberJeden(vektor* A, int index);

int main(){
  vektor A = {0, NULL}; vypisVektor(&A);
  pridejPosledni (&A, 10); vypisVektor(&A);
  pridejPosledni (&A, 20); vypisVektor(&A);
  odeberVsechny (&A); vypisVektor(&A);
  pridejPrvni (&A, 30); vypisVektor(&A);
  pridejPrvni (&A, 40); vypisVektor(&A);
  pridejPrvni (&A, 50); vypisVektor(&A);
  odeberJeden (&A, 2); vypisVektor(&A);
  odeberJeden (&A, 0); vypisVektor(&A);
  odeberJeden (&A, 1); vypisVektor(&A);
  odeberJeden (&A, 0); vypisVektor(&A);
  
  return 0;
}

void vypisVektor(vektor* A){
  printf("Vektor: ");
  for (int i = 0; i < A->delka; i++){
    printf("%d ", A->pole[i]);
  }
  printf("\n");
}

void pridejPosledni(vektor* A, int cislo){
  A->delka++;
  A->pole = realloc(A->pole, A->delka * sizeof(int));
  
  if (A->pole == NULL){
    printf("Chyba\n");
    return;
  }
  
  A->pole[A->delka - 1] = cislo;
}

void odeberVsechny(vektor* A){
  free (A->pole);
  A->pole = NULL;
  A->delka = 0;
}

void pridejPrvni(vektor* A, int cislo){
  A->delka++;
  A->pole = realloc(A->pole, A->delka * sizeof(int));
  
  if (A->pole == NULL){
    fprintf(stderr, "Chyba\n");
    exit(1);
  }
  
  for (int i = A->delka -1; i > 0; i--){
    A->pole[i] = A->pole[i-1];
  }
  A->pole[0] = cislo;
}

void odeberJeden(vektor* A, int index){
  if (index < 0 || index > A->delka - 1)
    return;

  
  char *tmp = malloc(A->delka * sizeof(int));
  
  for (int i = 0; i < A->delka; i++){
    if (i != index){
      tmp[i] = A->pole[i];
    }
  }
  A->delka--;
  A->pole = realloc(A->pole, A->delka * sizeof(int));
  for (int i = 0; i < A->delka; i++){
    A->pole[i] = tmp[i];
  }
  free(tmp);
}
