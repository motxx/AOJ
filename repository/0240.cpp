#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

class G {
 public:
  double b, r, t;
  int y;
  double gn;

  double power(double a, int p) {
    if (p == 0) return 1;
    return a * power(a, p - 1);
  }

  void setGn() {
    if (t == 1) {
      gn = 10000 * (1 + y * r / 100);
    } else if (t == 2) {
      gn = 10000 * power((1 + r / 100), y);
    } else
      assert(0);
  }

  bool operator<(const G &t) const { return gn != t.gn ? gn < t.gn : b < t.b; }
};

int main() {
  G Ginko[52];
  int n, y;

  while (cin >> n >> y, n) {
    for (int i = 0; i < n; i++) {
      cin >> Ginko[i].b >> Ginko[i].r >> Ginko[i].t;
      Ginko[i].y = y;
      Ginko[i].setGn();
    }

    sort(Ginko, Ginko + n);

    cout << Ginko[n - 1].b << endl;
  }
  return 0;
}