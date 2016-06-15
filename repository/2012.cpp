#include <cmath>
#include <iostream>

using namespace std;

int pw(int n, int p) {
  if (n == 0) return 0;
  if (p == 0) return 1;
  if (p == 1) return n;
  return n * pw(n, p - 1);
}

int computeM(int e) {
  int ret = e;

  // zが最も自由度の小さい数なので、zから決定していく。

  for (int y = 0; y <= sqrt(e); y++) {
    for (int z = 0; z <= sqrt(e); z++) {
      int temp = pw(y, 2) + pw(z, 3);
      int x = e - temp;
      if (x < 0) x = 0;
      if (x + temp == e) ret = min(x + y + z, ret);
    }
  }

  return ret;
}

int main(void) {
  int e, m;

  while (1) {
    cin >> e;
    if (e == 0) break;
    m = computeM(e);
    cout << m << endl;
  }
  return 0;
}