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

void main_();
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  main_();
  return 0;
}

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

int dp[2011][2011][2];  // ﾃｦﾂｬﾂ｡ﾃ｣ﾂ?ｫﾃ､ﾂｽﾂｿﾃ｣ﾂ??､ﾂｽﾂ催ｧﾂｽﾂｮSi, Tj,
                        // ﾃｦﾂｬﾂ｡ﾃ｣ﾂ?ｮﾃｦﾂ鳴?･ﾂｭﾂ?0: I, 1: O

void main_() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  const string IO = "IO";

  rep(i, 2011) rep(j, 2011) rep(k, 2) dp[i][j][k] = -1;

  rep(i, N) if (S[i] == 'I') rep(j, M) dp[i][j][0] = 0;
  rep(i, M) if (T[i] == 'I') rep(j, N) dp[j][i][0] = 0;

  rep(i, N + 1) rep(j, M + 1) rep(k, 2) {
    if (dp[i][j][k] < 0) {
      continue;
    }

    if (i < N && S[i] == IO[k]) {
      maximize(dp[i + 1][j][k ^ 1], dp[i][j][k] + 1);
    }
    if (j < M && T[j] == IO[k]) {
      maximize(dp[i][j + 1][k ^ 1], dp[i][j][k] + 1);
    }
  }

  int ans = 0;
  rep(i, N + 1) rep(j, M + 1) maximize(ans, dp[i][j][1]);
  cout << ans << endl;
}