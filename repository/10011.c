#include <stdio.h>

int main(void) {
  int n;
  int i;
  int a[100];

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  i--;
  printf("%d", a[i]);
  i--;

  for (; i >= 0; i--) {
    printf(" %d", a[i]);
  }

  printf("\n");

  return 0;
}