#include <stdio.h>
int main(void) {
  int n, m, i, in, out, Max;
  scanf("%d %d", &n, &m);
  Max = m;
  for (i = 0; i < n; i++) {
    scanf("%d", &in);
    m = m + in;
    scanf("%d", &out);
    m = m - out;
    if (m < 0) break;
    if (Max < m) {
      Max = m;
    }
  }
  if (m < 0) {
    printf("0\n");
  } else if (m > 0) {
    printf("%d\n", Max);
  }
  return 0;
}