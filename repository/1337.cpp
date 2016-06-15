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

template <class T>
constexpr bool in_range(T y, T x, T H, T W) {
  return 0 <= y && y < H && 0 <= x && x < W;
}

int X1[102], X2[102], Y1[102], Y2[102];
bool G[606][606];
int H, W, N;

int compress(int *x1, int *x2) {
  vector<int> xs;
  rep(i, N) REP(d, -1, 2) { xs.push_back(x1[i] + d), xs.push_back(x2[i] + d); }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  rep(i, N) {
    x1[i] = find(all(xs), x1[i]) - xs.begin();
    x2[i] = find(all(xs), x2[i]) - xs.begin();
  }

  return xs.size();
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

typedef pair<int, int> P;

void fill_bfs(vector<vector<bool>> &vis, int y, int x, queue<P> &online_q) {
  queue<P> q;
  q.emplace(y, x);
  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();
    rep(i, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (!in_range(ny, nx, H, W)) {
        continue;
      }
      if (vis[ny][nx]) {
        continue;
      }
      vis[ny][nx] = 1;
      if (G[ny][nx]) {
        online_q.emplace(ny, nx);
      } else {
        q.emplace(ny, nx);
      }
    }
  }
}

int count_the_regions() {
  int ret = 0;

  queue<P> q;
  q.emplace(0, 0);

  vector<vector<bool>> vis(H, vector<bool>(W));
  vis[0][0] = 1;
  if (!G[0][0]) {
    fill_bfs(vis, 0, 0, q);
    ret++;
  }

  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();
    rep(i, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (!in_range(ny, nx, H, W)) {
        continue;
      }
      if (vis[ny][nx]) {
        continue;
      }
      vis[ny][nx] = 1;
      if (G[y][x] && !G[ny][nx]) {
        fill_bfs(vis, ny, nx, q);
        ret++;
      } else {
        q.emplace(ny, nx);
      }
    }
  }

  return ret;
}

int main() {
  for (; cin >> N && N;) {
    zero(X1);
    zero(X2);
    zero(Y1);
    zero(Y2);
    rep(i, N) {
      int l, t, r, b;
      cin >> l >> t >> r >> b;
      X1[i] = (l + 1) * 2, X2[i] = (r + 1) * 2, Y1[i] = (b + 1) * 2,
      Y2[i] = (t + 1) * 2;
    }

    W = compress(X1, X2);
    H = compress(Y1, Y2);

    zero(G);
    rep(i, N) {
      REP(x, X1[i], X2[i] + 1) { G[Y1[i]][x] = G[Y2[i]][x] = 1; }
      REP(y, Y1[i], Y2[i] + 1) { G[y][X1[i]] = G[y][X2[i]] = 1; }
    }
    //    rep(i, H) { rep(j, W) cout << G[i][j]; cout << endl; }
    cout << count_the_regions() << endl;
  }

  return 0;
}