#include <bits/stdc++.h>
double const pi = acos(-1);
using namespace std;

int main() {
  double a, b, c, d;
  while (cin >> a >> b >> c >> d && a != -1) {
    a = a * pi / 180.;
    b = b * pi / 180.;
    c = c * pi / 180.;
    d = d * pi / 180.;
    cout << (int)round(6378.1 * acos(cos(a) * cos(b) * cos(c) * cos(d) +
                                     sin(b) * cos(a) * sin(d) * cos(c) +
                                     sin(a) * sin(c)))
         << endl;
  }
  return 0;
}