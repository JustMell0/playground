#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  float x;
  float y;
} bod;

bool jeFunkce(int delka, bod pole[]) {
  for (int i = 0; i < delka; i++) {
    for (int j = 0; j < delka; j++) {
      if (pole[i].x == pole[j].x && pole[i].y != pole[j].y) {
        return false;
      }
    }
  }
  return true;
}

float maxFunkce(int delka, bod pole[]) {
  float max = 0;
  for (int i = 0; i < delka; i++) {
    if (pole[i].y > max) {
      max = pole[i].x;
    }
  }
  return max;
}

float vzdalenost(bod A, bod B) {
  float ans;
  ans = pow((B.x - A.x), 2) + pow(B.y - A.y, 2);
  return sqrtf(ans);
}

void stred(int delka, bod pole[], bod *S) {
  float x = 0, y = 0;
  for (int i = 0; i < delka; i++) {
    x += pole[i].x;
    y += pole[i].y;
  }
  S->x = x / delka;
  S->y = y / delka;
}

int nejblizsi(int delka, bod pole[], bod *S) {
  bod min = {0.0, 0.0};
  int j = 0;
  for (int i = 0; i < delka; i++) {
    if (vzdalenost(*S, pole[i]) < vzdalenost(*S, min)) {
      min = pole[i];
      j = i;
    }
  }
  return j;
}

int main() {
  bod pole[4];
  bod S;

  for (int i = 0; i < 4; i++) {
    scanf("%f %f", &pole[i].x, &pole[i].y);
  }

  stred(4, pole, &S);
  int i = nejblizsi(4, pole, &S);
  printf("Souradnice stredu (%f, %f)\n", S.x, S.y);
  printf("Nejblizsi prvek je (%f %f)\n", pole[i].x, pole[i].y);

  if (jeFunkce(4, pole)) {
    printf("Je funkce\n");
  } else {
    printf("Neni funkce\n");
  }
  printf("Maximum: %f\n", maxFunkce(4, pole));
  return 0;
}
