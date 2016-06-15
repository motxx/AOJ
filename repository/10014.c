#include <stdio.h>

int main(void) {
  int h = -1, w = -1;
  int i, j;
  char symbol;

  while (1) {
    scanf("%d %d", &h, &w);
    if ((h == 0) && (w == 0)) break;

    symbol = '#';

    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        printf("%c", symbol);
        if (symbol == '#') {
          symbol = '.';
        } else {
          symbol = '#';
        }
      }
      printf("\n");

      if (i % 2 == 0) {
        symbol = '.';
      } else {
        symbol = '#';
      }
    }
    printf("\n");
  }

  return 0;
}