#include <stdio.h>
int main(void) {
  int p[5], j[5], i, min = (1 << 20), t, k;
  scanf("%d %d %d", &p[0], &p[1], &p[2]);
  scanf("%d %d", &j[0], &j[1]);
  for (i = 0; i < 3; i++) {
    for (k = 0; k < 2; k++) {
      t = p[i] + j[k] - 50;
      if (min > t) {
        min = t;
      }
    }
  }
  printf("%d\n", min);
  return 0;
}