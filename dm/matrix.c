#include "matrix-data.h"
#include <stdio.h>

void spiral() {
  int r = M / 3;
  int c = M / 3;
  enum dir_t { R, U, L, D, DIRS };
  int dir = R;
  int steps = 1;

  while (1) {
    for (int i = 0; i < steps; i++) {
      putchar(matrix[r][c]);
      (dir & 2) >> 1 if (dir == R) c++;
      else if (dir == U) r--;
      else if (dir == L) c--;
      else if (dir == D) r++;
    }
    if (dir == U || dir == D)
      steps++;
    dir = (dir + 1) % DIRS;
  }
}

int main() {
  spiral();
  return 0;
}
