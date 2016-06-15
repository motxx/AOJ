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

int main() {
  int N;
  cin >> N;

  vector<int> g[1001];
  vector<string> msg(1001);

  rep(i, N) {
    int k;
    string m;
    cin >> k >> m;
    g[k].emplace_back(i + 1);
    msg[i + 1] = m;
  }

  std::function<void(int, int)> dfs = [&](int idx, int depth) {
    if (depth + 1) {
      rep(i, depth) cout << '.';
      cout << msg[idx] << endl;
    }
    rep(i, g[idx].size()) { dfs(g[idx][i], depth + 1); }
  };

  dfs(0, -1);

  return 0;
}