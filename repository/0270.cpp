#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<int> A(600001);
  rep(i, N) {
    int x;
    cin >> x;
    A[x] = x;
  }

  int now = 0;
  rep(i, 600001) {
    if (now < A[i]) {
      now = A[i];
    } else {
      A[i] = now;
    }
  }

  rep(_, Q) {
    int ans = 0;
    int p;
    cin >> p;
    for (int i = p - 1; i < 600001; i += p) {
      ans = max(ans, A[i] % p);
    }
    cout << ans << endl;
  }

  return 0;
}