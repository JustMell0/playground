#include <stdio.h>

void calc(float a, float b, char op);

int main() {
  float a;
  float b;

  puts("Enter a number: ");
  scanf("%f", &a);
  puts("Enter another number: ");
  scanf("%f", &b);
  puts("Enter operator: ");
  char op;
  scanf(" %c", &op);

  calc(a, b, op);
}

void calc(float a, float b, char op) {
  float result;
  switch (op) {
  case '+':
    result = a + b;
    break;
  case '-':
    result = a - b;
    break;
  case '*':
    result = a * b;
    break;
  case '/':
    if (b == 0) {
      puts("Cannot divide by zero");
      return;
    }
    result = a / b;
    break;
  default:
    puts("Invalid operator");
    return;
  }
  printf("%.2f %c %.2f = %.2f\n", a, op, b, result);
}
