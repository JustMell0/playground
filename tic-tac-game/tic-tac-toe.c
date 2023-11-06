#include <stdio.h>

void intro_game() {
  puts("\tTip Toe game\n");

  puts("\t    1|2|3");
  puts("\t    -+-+-");
  puts("\t    4|5|6");
  puts("\t    -+-+-");
  puts("\t    7|8|9\n");

  puts("\tFirst player: X");
  puts("\tSecond player: O\n");

  puts("\t1. Start game");
  puts("\t2. Exit\n");
}

void game() {
  char board[3][3];
  
}

int main() {
  int option;
  intro_game();
  scanf("%d", &option);
  switch (option) {
  case 1:
    game();
    break;
  case 2:
    puts("Game finished");
    break;
  default:
    puts("Invalid option");
    break;
  }
  return 0;
}
