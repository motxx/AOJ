#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int w;
  int cAng = 90, ang;
  char c;
  double x = 0.0, y = 0.0;

  while (cin >> w >> c >> ang) {
    if (w == 0 && ang == 0) break;
    x += w * cos(cAng * M_PI / 180.0), y += w * sin(cAng * M_PI / 180.0);
    cAng -= ang;
  }
  printf("%d\n%d\n", (int)x, (int)y);
  return 0;
}