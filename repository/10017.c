#include <stdio.h>

int main(void) {
  int num;
  int n, x;
  int i, j, k;

  while (1) {
    scanf("%d%d", &n, &x);
    if ((n == 0) && (x == 0)) {
      break;
    }

    num = 0;

    for (i = 1; i <= n - 2; i++) {
      for (j = i + 1; j <= n - 1; j++) {
        for (k = j + 1; k <= n; k++) {
          // printf("i = %d, j = %d, k = %d\n", i, j, k);
          if ((i + j + k) == x) num++;
        }
      }
    }

    printf("%d\n", num);
  }

  return 0;
}