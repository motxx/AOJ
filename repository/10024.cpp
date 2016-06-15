#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
  double x1, x2, y1, y2;
  double res;

  cin >> x1 >> y1 >> x2 >> y2;
  res = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

  printf("%lf\n", res);
  // cout.width(.10);
  // cout << res << endl;

  return 0;
}