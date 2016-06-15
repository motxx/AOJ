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

int sumi[35][35];
int H, W, S;

int sum(int i, int j, int k, int l) {
  return sumi[k][l] - (i ? sumi[i - 1][l] : 0) - (j ? sumi[k][j - 1] : 0) +
         (i && j ? sumi[i - 1][j - 1] : 0);
}

typedef pair<int, int> pii;  // pattern, yobi

pii dp[35][35][35][35];

int yobi(int i, int j, int k, int l) {
  return S - sum(0, 0, H - 1, W - 1) + sum(i, j, k, l);
}

pii dfs(int i, int j, int k, int l) {
  auto &ret = dp[i][j][k][l];
  if (ret.first != -1) {
    return ret;
  }

  ret = {1, yobi(i, j, k, l)};

  REP(a, i, k) {
    if (yobi(i, j, a, l) < 0) continue;
    if (yobi(a + 1, j, k, l) < 0) continue;
    auto x = dfs(i, j, a, l);
    auto y = dfs(a + 1, j, k, l);
    ret = max(
        ret,
        {x.first + y.first,
         min(x.second,
             y.second)});  // ﾃ､ﾂｻﾂｻﾃｦﾂ?湘｣ﾂ?ｮ ->
                           // ﾃ､ﾂｺﾂ暗･ﾂつ凖･ﾂ環崚｣ﾂ?ｮﾃｦﾂ慊?･ﾂｰﾂ湘･ﾂ?､ﾃ｣ﾂつ津ｦﾂ慊?･ﾂ､ﾂｧﾃ･ﾂ個?
  }

  REP(b, j, l) {
    if (yobi(i, j, k, b) < 0) continue;
    if (yobi(i, b + 1, k, l) < 0) continue;
    auto x = dfs(i, j, k, b);
    auto y = dfs(i, b + 1, k, l);
    ret = max(ret, {x.first + y.first, min(x.second, y.second)});
  }

  return ret;
}

int main() {
  for (; cin >> H >> W >> S && (H | W | S);) {
    vector<vector<int>> U(H, vector<int>(W));
    rep(i, H) rep(j, W) { cin >> U[i][j]; }

    zero(sumi);

    rep(i, H) rep(j, W) {
      sumi[i][j] = U[i][j];
      if (i) sumi[i][j] += sumi[i - 1][j];
      if (j) sumi[i][j] += sumi[i][j - 1];
      if (i && j) sumi[i][j] -= sumi[i - 1][j - 1];
    }

    rep(i, 35) rep(j, 35) rep(k, 35) rep(l, 35) dp[i][j][k][l] = {-1, -1};

    auto k = dfs(0, 0, H - 1, W - 1);
    cout << k.first << " " << k.second << endl;
  }

  return 0;
}