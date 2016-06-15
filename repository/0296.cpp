#include <stdio.h>
int main() {
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  printf("%d\n", (a + b * 5 + c * 10 + d * 50 + e * 100 + f * 500 >= 1000));
}