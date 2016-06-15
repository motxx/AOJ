#include <stdio.h>
int main() {
  int W, H, x, y, r;
  scanf("%d%d%d%d%d", &W, &H, &x, &y, &r);
  if (x - r >= 0 && x + r <= W && y - r >= 0 && y + r <= H)
    puts("Yes");
  else
    puts("No");
  return 0;
}