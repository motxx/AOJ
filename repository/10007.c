#include <stdio.h>

int main(void) {
  int i;
  int x, y;
  int sub;

  for (i = 1;; i++) {
    scanf("%d %d", &x, &y);
    if ((x == 0) && (y == 0)) break;
    if (x > y) {
      sub = x;
      x = y;
      y = sub;
    }

    printf("%d %d\n", x, y);
  }
  return 0;
}