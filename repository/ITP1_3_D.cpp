#include <stdio.h>
int main() {
  int cnt = 0, a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  for (int i = a; i <= b; i++) cnt += c % i == 0;
  printf("%d\n", cnt);
  return 0;
}