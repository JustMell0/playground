#include <stdio.h>

int main() {
  int a, f1 = 1, f2 = 1;
  scanf ("%d", &a);
  for (int i = 2; i < a; i++) {
    int tmp = f1;
    f1 = f2;
    f2 = tmp + f2;
  }
  printf("%d\n", f2);
  return 0;
}
