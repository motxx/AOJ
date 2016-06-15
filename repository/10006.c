#include <stdio.h>

int main(void) {
  int i;
  int dat;

  for (i = 1;; i++) {
    scanf("%d", &dat);
    if (dat == 0) break;
    printf("Case %d: %d\n", i, dat);
  }
  return 0;
}