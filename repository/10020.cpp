#include <stdio.h>

int main(void) {
  int alphabet[26] = {0};
  char str[10000];
  int i, j;
  char ch;

  while ((ch = getchar()) != EOF) {
    ungetc(ch, stdin);
    fgets(str, sizeof str, stdin);

    for (i = 0; str[i] != '\n'; i++) {
      if ((str[i] >= 'A') && (str[i] <= 'z')) {
        if (str[i] < 'a') {
          alphabet[str[i] - 'A']++;
        } else {
          alphabet[str[i] - 'a']++;
        }
      }
    }
  }
  for (i = 0; i < 26; i++) {
    printf("%c : %d\n", 'a' + i, alphabet[i]);
  }

  return 0;
}