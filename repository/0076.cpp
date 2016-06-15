#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int n;

  while (cin >> n && n != -1) {
    double x = 1.0, y = 0.0, r, th = 0.0;
    for (int i = 1; i < n; i++) {
      r = sqrt(x * x + y * y);
      th += atan(1.0 / r);
      r = sqrt(r * r + 1.0);
      x = r * cos(th), y = r * sin(th);
    }
    printf("%.2f\n%.2f\n", x, y);
  }

  return 0;
}