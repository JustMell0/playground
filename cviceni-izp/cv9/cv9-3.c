#include <stdio.h>
#include <string.h>

typedef struct Sosoba {
  char prijmeni[10];
  char jmeno[10];
} osoba;

void vypisPole(int delka, osoba pole[]) {
  for (int i = 0; i < delka; i++) {
    printf("(%s %s)", pole[i].prijmeni, pole[i].jmeno);
  }
  printf("\n");
}

int porovnej(osoba A, osoba B) {
  int ans = strcmp(A.prijmeni, B.prijmeni);
  if (ans == 0) {
    ans = strcmp(A.jmeno, B.jmeno);
  }
  return ans;
}

void vymen(osoba *A, osoba *B) {
  osoba tmp = *A;
  *A = *B;
  *B = tmp;
}

int nejmensi (int delka, osoba pole[]){
  int min = 0;
  for (int i = 0; i < delka; i++) {
    if (porovnej(pole[i], pole[min]) < 0) {
      min = i - 1;
    }
  }
  return min;
}

void serad(int delka, osoba pole[]) {
  for (int i = 0; i < delka; i++){
    int min = nejmensi(delka - i, pole);
    vymen(&pole[i], &pole[min]);
  }
}

int main(){
  osoba pole[5] = {{"BBB", "CCC"},
                  {"CCC", "CCC"},
                  {"BBB", "BBB"},
                  {"AAA", "DDD"},
                  {"DDD", "AAA"}};
  vypisPole(5, pole);
  if (porovnej(pole[0], pole[1]) < 0) printf("Ruzna prijmeni (0,1) OK\n");
  if (porovnej(pole[0], pole[2]) > 0) printf("Ruzna jmena (0,2) OK\n");

  vymen(&pole[0], &pole[2]);
  vypisPole(5, pole);
  if (porovnej(pole[0], pole[2]) < 0) printf("Vymena osob (0,2) OK\n");
  if (nejmensi(5, pole) == 3) printf("Minimum osob (3) OK\n");
  serad(5, pole);
  vypisPole(5, pole);
  return 0;
}
