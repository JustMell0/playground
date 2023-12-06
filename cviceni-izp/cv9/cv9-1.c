#include <stdio.h>

int fibRek(int n){
  int ans = 0;
  
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fibRek(n-1) + fibRek(n-2);
}

int fibCyk(int n){
  int a = 0, b = 1, c = 0;

  while (n - 1 > 0){
    c = a + b;
    a = b;
    b = c;
    n--;
  }
  
  return c;
}

int main() {
  int a;
  scanf("%d", &a);
  printf("%d\n", fibRek(a));
  printf("%d\n", fibCyk(a));
  return 0;
}
