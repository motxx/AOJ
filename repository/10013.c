#include <stdio.h>

int main(void) {
  int h = -1, w = -1;
  int i, j;

  while (1) {
    scanf("%d %d", &h, &w);
    if ((h == 0) && (w == 0)) break;

    for (i = 0; i < w; i++) {
      printf("#");
    }
    printf("\n");

    for (i = 1; i < h - 1; i++) {
      printf("#");
      for (j = 1; j < w - 1; j++) {
        printf(".");
      }
      printf("#");
      printf("\n");
    }

    for (i = 0; i < w; i++) {
      printf("#");
    }
    printf("\n\n");
  }

  return 0;
}