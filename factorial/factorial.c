#include <stdio.h>

int main () {
  int a, i = 0;
  long long int f = 1;
  scanf("%d", &a);
  while (i < a){
    i++;
    f = f * i;
  }
  printf("%lld", f);
  return 0;
}
