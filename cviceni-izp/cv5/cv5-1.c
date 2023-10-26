#include <stdio.h>

int main() {
  int a;
  int sum = 0;
  while (scanf("%d", &a) > 0) {
    sum += a;
  }
  printf("Suma je %d\n", sum);
  return 0;
}
