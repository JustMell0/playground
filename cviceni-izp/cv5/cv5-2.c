#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Nedostatek argumentu\n");
    return 2;
  }
  FILE *file;
  file = fopen(argv[1], "r");
  if (file == NULL) {
    fprintf(stderr, "Soubor %s se nepodarilo otevrit\n", argv[1]);
    return 1;
  }
  int cnt = -1;
  char x;
  while (fscanf(file, "%c", &x) != EOF) {
    cnt++;
  }
  printf("Soubor %s obsahuje %d znaku\n", argv[1], cnt);
  fclose(file);
  return 0;
}
