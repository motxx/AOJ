#include <stdio.h>

int main(void) {
  int i, sum = 0, total, kakaku;

  while (1) {
    sum = 0;
    scanf("%d", &total);

    if (total == 0) break;

    for (i = 0; i < 9; i++) {
      scanf("%d", &kakaku);
      sum += kakaku;
    }

    printf("%d\n", (total - sum));
  }

  return 0;
}