#include <stdio.h>

int hledej(int zacatek, int konec, int pole [], int cislo) {
  int stred = (zacatek + konec) / 2;
  if (pole[stred] == cislo)
    return stred;
  else if (zacatek == konec)
    return -1;
  else if (cislo > pole[stred])
      return hledej(stred + 1, konec, pole, cislo);
  else if (cislo < pole[stred])
      return hledej (zacatek, stred - 1, pole, cislo);
  return 0;
}

int main() {
  int pole[7] = {0, 2, 3, 5, 6, 8, 9};
  int cislo;
  scanf("%d", &cislo);
  int c = hledej(0, 6, pole, cislo);
  if (c != -1)
    printf("cislo %d nalezeno na indexu %d\n", cislo, c);
  else 
    printf("cislo %d nenalezeno\n", cislo);
  return 0;
}
