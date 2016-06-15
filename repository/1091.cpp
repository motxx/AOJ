#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

double heron(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
  double a, l, x;

  while (cin >> a >> l >> x)
    printf("%.6f\n", heron(a, l, l) + 2 * heron(l, (l + x) / 2, (l + x) / 2));

  return 0;
}