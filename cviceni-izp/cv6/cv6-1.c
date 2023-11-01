#include <stdio.h>

typedef struct {
  char z1;
  char z2;
  int x;
} XXX;

typedef struct {
  char z1;
  int x;
  char z2;
} YYY;

int main() {
  int pole[3];
  printf("Adresa celeho pole je %d %lu\n", *pole, sizeof(pole));
  for (int i = 0; i < 3; i++)
    printf("Adresa polozky %d je %d %lu\n", i, pole[i], sizeof(pole[i]));
  printf("%lu\n", sizeof(XXX));
  printf("%lu\n", sizeof(YYY));

  return 0;
}
