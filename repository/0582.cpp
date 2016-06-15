#include <stdio.h>
int main(void) {
  int a, b, c;
  int x;
  int d = 0, e = 0, t = 0;

  while (1) {
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

    if (c <= b - a || a + b <= c) break;

    if (c * c > a * a + b * b) {
      d++;
    }
    if (c * c < a * a + b * b) {
      e++;
    }
    if (c * c == a * a + b * b) {
      t++;
    }
  }
  printf("%d %d %d %d\n", d + e + t, t, e, d);
  return 0;
}