#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, nums[1000], a[1000], b[1000], c[1000];
  int p, q, r, s;
  while (cin >> N && N) {
    rep(i, N) cin >> nums[i] >> a[i] >> b[i] >> c[i];
    cin >> p >> q >> r >> s;
    bool ok = 0;
    rep(i, N) {
      if (a[i] > p || b[i] > q || c[i] > r ||
          4 * a[i] + 9 * b[i] + 4 * c[i] > s)
        ;
      else {
        cout << nums[i] << endl;
        ok = 1;
      }
    }
    if (!ok) {
      cout << "NA\n";
    }
  }

  return 0;
}