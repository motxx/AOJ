#include <stdio.h>
int main(void) {
  int a, b, c;
  int x, n, i;

  scanf("%d", &n);
  if (n == 2) {
    scanf("%d%d", &a, &b);

    if (a > b) {
      x = a;
      a = b;
      b = x;
    }
    while (1) {
      x = b % a;
      if (x == 0) break;
      b = a;
      a = x;
    }

  } else {
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) {
      x = a;
      a = b;
      b = x;
    }
    if (b > c) {
      x = b;
      b = c;
      c = x;
    }
    if (a > b) {
      x = a;
      a = b;
      b = x;
    }

    while (1) {
      x = c % b;
      if (x == 0) break;
      c = b;
      b = x;
    }
    while (1) {
      x = b % a;
      if (x == 0) break;
      b = a;
      a = x;
    }
  }

  for (i = 1; i <= a; i++) {
    if (a % i == 0) {
      printf("%d\n", i);
    }
  }

  return 0;
}