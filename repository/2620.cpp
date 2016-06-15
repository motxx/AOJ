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

template <class T = int>
using VT = vector<T>;
template <class T = int>
using VVT = vector<vector<T>>;

template <class T>
constexpr bool in_range(T y, T x, T H, T W) {
  return 0 <= y && y < H && 0 <= x && x < W;
}
template <class T>
using PQ_G = priority_queue<T, vector<T>, greater<T>>;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

const string dir = "LURD";

int main() {
  int W, H, N;
  cin >> W >> H >> N;
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  VVT<bool> P(H + 10, VT<bool>(W + 10));
  VVT<map<pair<int, int>, int>> mat(H, VT<map<pair<int, int>, int>>(W));

  rep(_, N) {
    int x, y;
    cin >> x >> y;
    P[y][x] = 1;
    int T;
    cin >> T;
    string op;
    cin >> op;
    rep(t, T) {
      int n = op.size();
      rep(i, n) {
        int ny = y + dy[dir.find(op[i])], nx = x + dx[dir.find(op[i])];
        if (!in_range(ny, nx, H, W)) {
          continue;
        }
        P[ny][nx] = 1;
        mat[y][x][{ny, nx}]++;
        y = ny, x = nx;
      }
    }
  }

  PQ_G<tuple<int, int, int>> pq;
  pq.emplace(0, sy, sx);
  VVT<int> dist(H + 10, VT<int>(W + 10, inf));
  dist[sy][sx] = 0;
  while (!pq.empty()) {
    int cost, y, x;
    tie(cost, y, x) = pq.top();
    pq.pop();
    if (y == ty && x == tx) {
      cout << cost << endl;
      return 0;
    }
    rep(i, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (!in_range(ny, nx, H + 1, W + 1)) {
        continue;
      }
      int ncost = cost;
      if (i == 0) {
        if (P[ny][nx] && (ny + dy[1] >= 0 && P[ny + dy[1]][nx])) {
          ncost +=
              mat[ny][nx][{ny + dy[1], nx}] + mat[ny + dy[1]][nx][{ny, nx}];
        }
      }
      if (i == 1) {
        if ((nx + dx[0] >= 0 && P[ny][nx + dx[0]]) && P[ny][nx]) {
          ncost +=
              mat[ny][nx + dx[0]][{ny, nx}] + mat[ny][nx][{ny, nx + dx[0]}];
        }
      }
      if (i == 2) {
        if ((nx + dx[0] >= 0 && P[ny][nx + dx[0]]) &&
            (ny + dy[1] >= 0 && nx + dx[0] >= 0 && P[ny + dy[1]][nx + dx[0]])) {
          ncost += mat[ny][nx + dx[0]][{ny + dy[1], nx + dx[0]}] +
                   mat[ny + dy[1]][nx + dx[0]][{ny, nx + dx[0]}];
        }
      }
      if (i == 3) {
        if ((ny + dy[1] >= 0 && nx + dx[0] >= 0 && P[ny + dy[1]][nx + dx[0]]) &&
            (ny + dy[1] >= 0 && P[ny + dy[1]][nx])) {
          ncost += mat[ny + dy[1]][nx + dx[0]][{ny + dy[1], nx}] +
                   mat[ny + dy[1]][nx][{ny + dy[1], nx + dx[0]}];
        }
      }
      if (dist[ny][nx] > ncost) {
        dist[ny][nx] = ncost;
        pq.emplace(ncost, ny, nx);
      }
    }
  }

  return 0;
}