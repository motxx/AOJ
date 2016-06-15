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
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
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

int H, W, N;
vector<string> G;

bool solve() {
  auto mark = [](const int y, const int x, vector<vector<bool>>& vis) {
    bool ok = 0;
    char c = G[y][x];
    vis[y][x] = 1;
    int sx = -1, tx = -1;
    for (int i = x; i >= -1; i--)
      if (i == -1 || G[y][i] != c) {
        sx = i + 1;
        break;
      }
    for (int i = x; i <= W; i++)
      if (i == W || G[y][i] != c) {
        tx = i - 1;
        break;
      }
    assert((sx + 1) && (tx + 1));
    if (tx - sx + 1 >= N) {
      ok = 1;
      REP(i, sx, tx + 1) { vis[y][i] = 1; }
    }
    int sy = -1, ty = -1;
    for (int i = y; i >= -1; i--)
      if (i == -1 || G[i][x] != c) {
        sy = i + 1;
        break;
      }
    for (int i = y; i <= H; i++)
      if (i == H || G[i][x] != c) {
        ty = i - 1;
        break;
      }
    assert((sy + 1) && (ty + 1));
    if (ty - sy + 1 >= N) {
      ok = 1;
      REP(i, sy, ty + 1) { vis[i][x] = 1; }
    }
    if (!ok) {
      vis[y][x] = 0;
    }
    return ok;
  };

  auto fill = [](vector<vector<bool>>& vis) {
    rep(i, H) rep(j, W) {
      if (vis[i][j]) {
        G[i][j] = '.';
      }
    }
  };

  auto drop = []() {
    rep(j, W) {
      vector<char> col;
      for (int i = H - 1; i >= 0; i--) {
        if (G[i][j] != '.') {
          col.push_back(G[i][j]);
        }
      }
      for (int i = H - 1; i >= H - (int)col.size(); i--) {
        G[i][j] = col[H - 1 - i];
      }
      for (int i = H - 1 - (int)col.size(); i >= 0; i--) {
        G[i][j] = '.';
      }
    }
  };

  std::function<void()> simulate = [&]() {
    drop();
    while (1) {
      vector<vector<bool>> vis(H, vector<bool>(W));
      bool ok = 0;
      rep(i, H) rep(j, W) {
        if (!vis[i][j] && G[i][j] != '.') {
          if (mark(i, j, vis)) {
            ok = 1;
          }
        }
      }
      if (ok) {
        fill(vis);
        drop();
      } else {
        break;
      }
    }
  };

  simulate();

  rep(i, H) rep(j, W) {
    if (G[i][j] != '.') {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> H >> W >> N;
  vector<string> F(H);
  rep(i, H) { cin >> F[i]; }

  rep(i, H) rep(j, W) {
    G = F;
    if (!in_range(i, j + 1, H, W)) {
      continue;
    }
    swap(G[i][j], G[i][j + 1]);
    if (solve()) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;

  return 0;
}