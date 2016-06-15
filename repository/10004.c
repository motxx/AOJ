#include <stdio.h>

int main(void) {
  int a, b, c, sub;

  scanf("%d %d %d", &a, &b, &c);

  if (a > b) {
    sub = a;
    a = b;
    b = sub;
  }
  if (b > c) {
    sub = b;
    b = c;
    c = sub;
  }
  if (a > b) {
    sub = a;
    a = b;
    b = sub;
  }

  printf("%d %d %d\n", a, b, c);
  return 0;
}