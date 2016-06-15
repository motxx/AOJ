#include <iostream>
using namespace std;

#define L 1000

long long getValue(long long x) {
  if (x <= L)
    return x + 1;
  else
    return L - x % (L + 1);
}

main() {
  int n;

  while (cin >> n) {
    long long cnt = 0;

    for (int i = 0; i <= 2 * L; i++) {
      int t = n - i;
      if (0 <= t && t <= 2 * L) {
        cnt += getValue(i) * getValue(t);
      }
    }

    cout << cnt << endl;
  }
}