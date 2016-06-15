#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int const INF = 1 << 29;

int main() {
  int N;
  while (cin >> N && N) {
    int t[N][N];
    rep(i, N) rep(j, N) cin >> t[i][j];

    bool left[N][N];
    memset(left, 0, sizeof left);
    bool right[N][N];
    memset(right, 0, sizeof right);

    rep(i, N) {
      int mn = INF;
      rep(j, N) { mn = min(mn, t[i][j]); }
      rep(j, N) {
        if (mn == t[i][j]) {
          left[i][j] = 1;
        }
      }
    }

    rep(i, N) {
      int mx = 0;
      rep(j, N) { mx = max(mx, t[j][i]); }
      rep(j, N) {
        if (mx == t[j][i]) {
          right[j][i] = 1;
        }
      }
    }

    int ans = 0;
    rep(i, N) rep(j, N) if (left[i][j] && right[i][j]) { ans = t[i][j]; }

    cout << ans << endl;
  }

  return 0;
}