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

struct point {
  int x, y;
  point operator+(point r) { return point{x + r.x, y + r.y}; }
  point operator-(point r) { return point{x - r.x, y - r.y}; }
};

struct segment {
  point s, t;
};

bool equals(point s, point t) { return s.x == t.x && s.y == t.y; }

bool equals(segment s, segment t) {
  return (equals(s.s, t.s) && equals(s.t, t.t)) ||
         (equals(s.t, t.s) && equals(s.s, t.t));
}

int dot(point p, point q) { return p.x * q.x + p.y * q.y; }

int cross(point p, point q) { return p.x * q.y - q.x * p.y; }

bool on_segment(segment s, point p) {
  if (equals(s.s, p)) return false;
  if (equals(s.t, p)) return false;
  if (cross(s.t - s.s, p - s.s) != 0) return false;
  if (dot(s.t - s.s, p - s.s) <= 0) return false;
  if (dot(s.s - s.t, p - s.t) <= 0) return false;
  return true;
}

bool parallel(segment s, segment t) { return cross(s.t - s.s, t.t - t.s) == 0; }

bool have_common_segment(segment s, segment t) {
  if (equals(s, t)) return true;
  if (!parallel(s, t)) return false;
  if (on_segment(s, t.s)) return true;
  if (on_segment(s, t.t)) return true;
  if (on_segment(t, s.s)) return true;
  if (on_segment(t, s.t)) return true;
  return false;
}

bool adjacent(int i, int j, vector<segment> *regions) {
  for (auto s : regions[i])
    for (auto t : regions[j])
      if (have_common_segment(s, t)) return true;
  return false;
}

bool same_coloring(int V, bool G[][10], int S) {
  rep(i, V) REP(j, i + 1, V) {
    if ((S >> i & 1) == 0) continue;
    if ((S >> j & 1) == 0) continue;
    if (G[i][j]) return false;
  }
  return true;
}

int main() {
  while (1) {
    int N;
    cin >> N;
    if (N == 0) break;
    vector<segment> regions[10];
    map<string, int> id;
    int V = 0;
    rep(_, N) {
      string name;
      cin >> name;
      if (!id.count(name)) {
        id[name] = V++;
      }
      vector<point> v;
      while (1) {
        int x;
        cin >> x;
        if (x == -1) break;
        int y;
        cin >> y;
        v.push_back(point{x, y});
      }
      rep(k, v.size()) {
        auto seg = segment{v[k], v[(k + 1) % v.size()]};
        regions[id[name]].push_back(seg);
      }
    }

    bool G[10][10] = {};
    rep(i, V) REP(j, i + 1, V) {
      if (adjacent(i, j, regions)) {
        G[i][j] = G[j][i] = 1;
      }
    }

    vector<int> same_col;
    rep(S, 1 << V) if (same_coloring(V, G, S)) same_col.push_back(S);

    int dp[1 << V];
    rep(i, 1 << V) dp[i] = 10;
    dp[0] = 0;

    rep(S, 1 << V) for (auto T : same_col) dp[S | T] =
        min(dp[S | T], dp[S] + 1);

    cout << dp[(1 << V) - 1] << endl;
  }

  return 0;
}