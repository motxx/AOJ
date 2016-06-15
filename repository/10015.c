#include <stdio.h>

int main(void) {
  int card[4][13] = {0};
  int i, j;
  int n;
  char cd;
  int num;

  scanf("%d", &n);
  // printf("n; %d\n", n);
  for (i = 0; i < n; i++) {
    scanf("%*c%c%d", &cd, &num);
    // printf("i: %d\n", i);
    if (cd == 'S') {
      card[0][num - 1] = 1;
      // printf("S[%d][%d]: %d\n", 0, num-1, card[0][num-1]);
    } else if (cd == 'H') {
      card[1][num - 1] = 1;
      // printf("H[%d][%d]: %d\n", 1, num-1, card[1][num-1]);
    } else if (cd == 'C') {
      card[2][num - 1] = 1;
      // printf("C[%d][%d]: %d\n", 2, num-1, card[2][num-1]);
    } else if (cd == 'D') {
      card[3][num - 1] = 1;
      // printf("D[%d][%d]: %d\n", 3, num-1, card[3][num-1]);
    }
    // else {
    //  printf("%d is founded. -> %c\n", cd, cd);
    //}
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 13; j++) {
      if (card[i][j] != 1) {
        switch (i) {
          case 0:
            printf("S ");
            break;
          case 1:
            printf("H ");
            break;
          case 2:
            printf("C ");
            break;
          case 3:
            printf("D ");
            break;
        }
        printf("%d\n", j + 1);
      }
    }
  }
  return 0;
}