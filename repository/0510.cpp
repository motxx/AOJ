#include <stdio.h>
int a, b, c, i;
main() {
  for (; i < 4; i++, scanf("%d", &a), b += a)
    ;
  for (; ~scanf("%d", &a); c += a)
    ;
  printf("%d\n", b > c ? b : c);
}