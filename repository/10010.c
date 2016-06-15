#include <stdio.h>

int main(void) {
  int a, b, c;
  char op;

  while (1) {
    scanf("%d %c %d", &a, &op, &b);

    if (op == '+') {
      c = a + b;
    } else if (op == '-') {
      c = a - b;
    } else if (op == '*') {
      c = a * b;
    } else if (op == '/') {
      c = a / b;
    } else if (op == '?') {
      return 0;
    }
    /*
    switch(op) {
    case '+':
      break;
    case '-':
      c = a - b;
      break;
    case '*':
      c = a * b;
      break;
    case '/':
      c = a / b;
      break;
    case '?': return 0;
  }
    */
    printf("%d\n", c);
  }

  return 0;
}