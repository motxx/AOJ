#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
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

constexpr int MOD = 1e9 + 7;

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> ws(N);
  vector<int> wsum(N);
  rep(i, N) { cin >> ws[i]; }

  sort(all(ws), greater<int>());

  rep(i, N) { wsum[i] = ws[i] + (i ? wsum[i - 1] : 0); }

  static int dp[2][10001];
  dp[0][W] = 1;

  rep(i, N) {
    fill(dp[(i + 1) & 1], dp[(i + 1) & 1] + W + 1, 0);
    rep(j, W + 1) {
      if (wsum[N - 1] - (i ? wsum[i - 1] : 0) <= j) {
        dp[(i + 1) & 1][j] = 0;
      } else {
        dp[(i + 1) & 1][j] = dp[i & 1][j];
      }

      if (ws[i] <= j) {
        dp[(i + 1) & 1][j - ws[i]] += dp[i & 1][j];
        dp[(i + 1) & 1][j - ws[i]] %= MOD;
      }
    }
  }

  int ans = 0;

  rep(i, W + 1) {
    ans += dp[N & 1][i];
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}