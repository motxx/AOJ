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
template <class T>
constexpr bool in_range(T y, T x, T H, T W) {
  return 0 <= y && y < H && 0 <= x && x < W;
}

typedef long long ll;
int const inf = 1 << 29;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int H, W;

void solve(vector<string> &G) {
  int res = 0;

  while (1) {
    bool ok = 0;
    rep(i, H) rep(j, W) {
      if (G[i][j] == '.') {
        map<char, vector<pair<int, int>>> mp;
        rep(k, 4) {
          int y = i, x = j;
          while (1) {
            y += dy[k], x += dx[k];
            if (!in_range(y, x, H, W)) break;
            if (G[y][x] != '.') {
              mp[G[y][x]].emplace_back(y, x);
              break;
            }
          }
        }

        for (auto &&e : mp) {
          if (e.second.size() > 1) {
            G[e.second[0].first][e.second[0].second] = '.';
            G[e.second[1].first][e.second[1].second] = '.';
            res += 2;
            ok = 1;
          }
        }
      }
    }
    if (!ok) break;
  }
  cout << res << endl;
}

int main() {
  cin >> H >> W;
  vector<string> G(H);
  rep(i, H) cin >> G[i];

  rep(i, H) rep(j, W) {
    if (isalpha(G[i][j])) {
      rep(k, 4) {
        int ni = i + dy[k], nj = j + dx[k];
        if (!in_range(ni, nj, H, W)) continue;
        if (G[ni][nj] == '.') G[ni][nj] = '-';
      }
    }
  }

  int k = 0;
  rep(i, H) {
    if (G[i] != string(W, '.')) G[k++] = G[i];
  }
  H = k;

  vector<string> T(W);
  rep(i, W) T[i].resize(H);
  rep(i, W) rep(j, H) { T[i][j] = G[j][i]; }

  k = 0;
  rep(i, W) {
    if (T[i] != string(H, '.')) T[k++] = T[i];
  }

  W = k;

  G.clear();
  G.resize(H);
  rep(i, H) G[i] = string(W, '.');

  rep(i, H) rep(j, W) G[i][j] = T[j][i] == '-' ? '.' : T[j][i];

  //  rep(i, H) cout << G[i] << endl;

  solve(G);

  return 0;
}