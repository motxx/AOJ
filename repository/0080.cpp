#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

#define EPS 1e-5

int main() {
  double q;
  while (cin >> q, q >= 0) {
    double x = q / 2;
    while (fabs(x * x * x - q) >= EPS * q) {
      x = x - (x * x * x - q) / (3 * x * x);
    }
    printf("%f\n", x);
  }

  return 0;
}