#include <stdio.h>

void vymen(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void obrat(int delka, int pole[]) {
  int c;
  for (int i = 0; i < delka / 2; i++) {
    c = pole[i];
    pole[i] = pole[delka - i - 1];
    pole[delka - i - 1] = c;
  }
}

int main() {
  int a = 5, b = 10;
  int pole[5] = {1, 2, 3, 4, 5};

  vymen(&a, &b);

  printf("%d %d\n", a, b);

  obrat(5, pole);

  for (int i = 0; i < 5; i++)
    printf("%d ", pole[i]);
  return 0;
}
