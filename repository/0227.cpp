#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  int n, m;
  int res;

  while (1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;

    res = 0;

    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    stable_sort(p, p + n);

    for (int i = n - 1; i >= 0;) {
      for (int j = 0; j < m - 1; j++) {
        if (i < 0) break;
        res += p[i];
        i--;
      }
      i--;
    }

    cout << res << endl;
  }

  return 0;
}