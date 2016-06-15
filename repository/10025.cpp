#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const double PI = acos(-1.0);

int main() {
  double a, b, theta;
  cin >> a >> b >> theta;
  theta *= PI / 180.0;

  double s = a * b * sin(theta) / 2.0;
  double c = sqrt(a * a + b * b - 2 * a * b * cos(theta));
  double l = a + b + c;
  double h = 2.0 * s / a;

  printf("%.10f\n%.10f\n%.10f\n", s, l, h);

  return 0;
}