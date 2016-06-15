#include <stdio.h>

int main(void) {
  int h = -1, w = -1;
  int i, j;

  while (1) {
    scanf("%d %d", &h, &w);
    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        printf("#");
      }
      printf("\n");
    }

    if ((h == 0) && (w == 0)) break;
    printf("\n");
  }

  return 0;
}