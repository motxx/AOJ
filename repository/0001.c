#include <stdio.h>

int main(void) {
  int i, j;
  int n = 10;
  int sub;
  int x[n];

  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }

  for (i = 0; i < n - 1; i++) {
    for (j = n - 1; i < j; j--) {
      if (x[j - 1] > x[j]) {
        sub = x[j];
        x[j] = x[j - 1];
        x[j - 1] = sub;
      }
    }
  }

  printf("%d\n%d\n%d\n", x[n - 1], x[n - 2], x[n - 3]);

  return 0;
}