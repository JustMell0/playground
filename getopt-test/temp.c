#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

void print_usage() {
  puts("Usage: temp -c <temp> | temp -f <temp>");
  exit(2);
}

void farenheit(float temp) {
  float f = ((temp * 9) / 5) + 32;
  printf("%.2f centigrade is %.2f farenheit\n", temp, f);
}

void centigrade(float temp) {
  float c = ((temp - 32) * 5) / 9;
  printf("%.2f farenheit is %.2f centigrade\n", temp, c);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    print_usage();
  }
  int option;
  int cflag = 0;
  int fflag = 0;
  while ((option = getopt(argc, argv, "c:f:")) != -1) {
    switch (option) {
    case 'c':
      if (cflag) {
        print_usage();
      } else {
        cflag++;
        fflag++;
      }
      farenheit(atof(optarg));
      break;

    case 'f':
      if (fflag) {
        print_usage();
      } else {
        fflag++;
        cflag++;
      }
      centigrade(atof(optarg));
      break;

    default:
      printf("Error\n");
    }
  }
}
