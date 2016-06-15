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

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) \
  { cout << #a << " = " << a << endl; }
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
  int H, W;
  cin >> H >> W;
  vector<string> G(H);
  vector<vector<int>> ans(H, vector<int>(W, -1));
  rep(i, H) cin >> G[i];

  rep(i, H) {
    rep(j, W) {
      if (G[i][j] == 'c') ans[i][j] = 0;
      if (j < W - 1 && ans[i][j] >= 0) ans[i][j + 1] = ans[i][j] + 1;
    }
  }

  rep(i, H) rep(j, W) printf("%d%c", ans[i][j], j == W - 1 ? '\n' : ' ');

  return 0;
}