#include <stdio.h>

int main(void) {
  int n, searchnum, cent;
  int i, count = 0;
  int begin, end;
  int a[100];

  while (1) {
    scanf("%d", &n);
    if (n == 0) break;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    scanf("%d", &searchnum);

    begin = 0;
    end = n - 1;
    cent = (begin + end) / 2;
    count = 0;
    while (begin <= end) {
      count++;
      // printf("count:%d\nbegin:%d\nend:%d\ncent:%d\n", count, begin, end,
      // cent);
      if (a[cent] == searchnum) {
        break;
      } else if (a[cent] < searchnum) {
        begin = cent + 1;
        cent = (begin + end) / 2;
      } else {
        end = cent - 1;
        cent = (begin + end) / 2;
      }
    }

    printf("%d\n", count);
  }

  return 0;
}