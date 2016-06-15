#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

#define chmax(a, x) a = max(a, x)

typedef long long ll;

int N, S, T;
ll dp[2][3100], ans;
ll A[3100], B[3100];

int main() {
  cin >> N >> T >> S;
  rep(i, N) cin >> A[i] >> B[i];

  rep(i, N) rep(j, T + 1) {
    chmax(dp[(i + 1) & 1][j], dp[i & 1][j]);
    if (j + B[i] <= T) {
      if (j < S && S < j + B[i]) continue;
      chmax(dp[(i + 1) & 1][j + B[i]], dp[i & 1][j] + A[i]);
      chmax(ans, dp[(i + 1) & 1][j + B[i]]);
    }
  }

  cout << ans << endl;

  return 0;
}