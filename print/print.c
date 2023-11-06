#include "print.h"
#include <stdarg.h>
#include <stdio.h>

int count (){
  return 0;
}

void print(const char *format, ...) {
  va_list args;
  va_start(args, format);

  while (*format != '\0') {
    if (*format == '%') {
      format++;

      switch (*format) {
      case 'd': {
        int temp = va_arg(args, int);
        char buf[1000];
        snprintf(buf, sizeof(buf), "%d", temp);
        fprintf(stdout, buf);
        break;
      }
      case 'f': {
        double temp = va_arg(args, double);
        char buf[1000];
        snprintf(buf, sizeof(buf), "%f", temp);
        fprintf(stdout, buf);
        break;
      }
      case 's': {
        const char *temp = va_arg(args, char *);
        fprintf(stdout, temp);
        break;
      }
      }
    } else {
      putchar(*format);
    }
    format++;
  }
  va_end(args);
}

int main() {
  int lol = 10;
  double kek = 10.23;
  char *kek1 = "hello";

  print("My vars: lol = %d, kek = %f, kek1=%s", lol, kek, kek1);
  return 0;
}
