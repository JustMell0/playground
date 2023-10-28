#include <stdio.h>

void start_game() {
  puts("Tip Toe game\n");

  puts("\t1|2|3");
  puts("\t-+-+-");
  puts("\t4|5|6");
  puts("\t-+-+-");
  puts("\t7|8|9\n");

  puts("First player: X");
  puts("Second player: O\n");

  puts("1. Start game");
  puts("2. Exit\n");
}

void game() {
  char board[3][3];
  (void)board;
}

int main() {
  int option;
  start_game();
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
