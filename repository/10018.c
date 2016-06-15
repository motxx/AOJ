#include <stdio.h>

#define diff 'a' - 'A'

int main(void) {
  char str[10000];
  int i;

  fgets(str, sizeof str, stdin);

  for (i = 0; i < 10000; i++) {
    if ((str[i] >= 'A') && (str[i] <= 'z')) {
      if (str[i] < 'a') {
        str[i] += diff;
      } else {
        str[i] -= diff;
      }
    } else if (str[i] == '\0') {
      break;
    }
  }
  printf("%s", str);

  return 0;
}