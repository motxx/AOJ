#include <cmath>
#include <iostream>
using namespace std;

#define EPS 1e-10

int main() {
  double x1, y1, x2, y2, x3, y3, x4, y4;

  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
    if (fabs((x1 - x2) * (x3 - x4) + (y1 - y2) * (y3 - y4)) < EPS)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}