#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  double xa, ya, ra;
  double xb, yb, rb;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> xa >> ya >> ra >> xb >> yb >> rb;

    double d = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    int res;

    if (ra + rb < d)
      res = 0;
    else if (d < ra - rb)
      res = 2;
    else if (d < rb - ra)
      res = -2;
    else
      res = 1;

    cout << res << endl;
  }

  return 0;
}