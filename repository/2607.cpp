#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

int N, D, X;
int P[11][11];
int dp[121111];

void solve() {
  int ans = X;
  dp[X] = X;
  rep(i, D - 1) {
    rep(j, N) {
      for (int x = 111111; x >= P[i][j]; x--)
        if (dp[x]) {
          dp[x - P[i][j]] = max(dp[x - P[i][j]], dp[x] - P[i][j] + P[i + 1][j]);
          ans = max(ans, dp[x - P[i][j]]);
        }
    }
    rep(x, 111111) { dp[dp[x]] = max(dp[dp[x]], dp[x]); }
  }

  cout << ans << endl;
}

int main() {
  cin >> N >> D >> X;

  rep(i, D) rep(j, N) cin >> P[i][j];

  solve();

  return 0;
}