#include <stdio.h>

int main(void) {
  int j, i, n, m, friend[501][501] = {0}, from, to, called[501] = {0};
  int count = 0;

  while (1) {
    for (i = 0; i < 501; i++) {
      for (j = 0; j < 501; j++) {
        friend[i][j] = 0;
      }
      called[i] = 0;
    }
    count = 0;

    scanf("%d", &n);

    scanf("%d", &m);

    if (m == 0 && n == 0) break;

    for (i = 0; i < m; i++) {
      scanf("%d %d", &from, &to);
      // printf("from: %d to: %d\n", from, to);
      friend[from][to] = 1;
      friend[to][from] = 1;
    }

    /*
    for(i=1; i <= n; i++)
      for(j=1; j <= n; j++)
    printf("friend[%d][%d]: %d\n", i, j, friend[i][j]);
    */

    called[0] = 1;
    called[1] = 1;

    for (i = 1; i <= n; i++) {
      if (friend[1][i] == 1) {
        if (called[i] == 0) {
          count++;
        }
        called[i] = 1;
        for (j = 1; j <= n; j++) {
          if (friend[i][j] == 1 && called[j] == 0) {
            called[j] = 1;
            count++;
          }
        }
      }
    }

    printf("%d\n", count);
  }
  return 0;
}