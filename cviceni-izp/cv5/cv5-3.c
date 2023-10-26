#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Sbody {
  float x;
  float y;
} bod;

typedef struct Skruznice {
  bod S;
  float r;
} kruznice;

float vzdalenost(bod A, bod B);

bool jeUvnitr(kruznice K, bod B) {
  float vA = vzdalenost(K.S, B);
  if (vA < K.r)
    return false;
  else
    return true;
}

float vzdalenost(bod A, bod B) {
  float ans;
  ans = pow((B.x - A.x), 2) + pow(B.y - A.y, 2);
  return sqrtf(ans);
}

int main() {
  kruznice K;
  bod B;
  scanf("%f %f %f", &K.S.x, &K.S.y, &K.r);
  scanf("%f %f", &B.x, &B.y);
  if (jeUvnitr(K, B))
    puts("Bod neni v kruznici");
  else
    puts("Bod je v kruznici");
  return 0;
}
