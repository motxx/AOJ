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

int main() {
  int H, W, N;
  while (cin >> H >> W >> N && (H | W | N)) {
    vector<vector<int>> G(H, vector<int>(W));
    rep(i, H) rep(j, W) { cin >> G[i][j]; }

    vector<vector<int>> dp(H + 10, vector<int>(W + 10));
    dp[0][0] = N - 1;
    rep(i, H) rep(j, W) {
      if (G[i][j]) {
        dp[i][j + 1] += (dp[i][j] + 1) / 2;
        dp[i + 1][j] += (dp[i][j]) / 2;
      } else {
        dp[i + 1][j] += (dp[i][j] + 1) / 2;
        dp[i][j + 1] += (dp[i][j]) / 2;
      }
    }

    std::function<pair<int, int>(int, int)> dfs = [&](int y, int x) {
      if (y >= H || x >= W) {
        return make_pair(y + 1, x + 1);
      }
      if (G[y][x]) {
        return dfs(y + dp[y][x] % 2, x + (dp[y][x] + 1) % 2);
      } else {
        return dfs(y + (dp[y][x] + 1) % 2, x + dp[y][x] % 2);
      }
    };

    auto k = dfs(0, 0);
    cout << k.first << " " << k.second << endl;
  }

  return 0;
}