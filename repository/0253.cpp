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
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

const double EPS = 1e-9;

using number = double;

struct point {
  number x, y;
  point operator+(point r) { return point{x + r.x, y + r.y}; }
  point operator+(const point& r) const { return point{x + r.x, y + r.y}; }
  point operator-(point r) { return point{x - r.x, y - r.y}; }
  point operator-(const point& r) const { return point{x - r.x, y - r.y}; }
  point operator*(point r) {
    return point{x * r.x - y * r.y, x * r.y + r.x * y};
  }
  void operator-=(point r) { x -= r.x, y -= r.y; }
  point nml() {
    return point{x / sqrt(x * x + y * y), y / sqrt(x * x + y * y)};
  }
};
point operator*(number k, point p) { return point{k * p.x, k * p.y}; }

struct line {
  point s, t;
};

typedef line segment;

number dot(point a, point b) { return a.x * b.x + a.y * b.y; }

number cross(point a, point b) { return a.x * b.y - a.y * b.x; }

number norm(point p) { return p.x * p.x + p.y * p.y; }

struct polygon : public vector<point> {
  number area2() {
    number ret{};
    rep(i, this->size()) ret +=
        cross((*this)[i], (*this)[(i + 1) % this->size()]);
    return abs(ret);
  }
};

int ccw(point a, point b, point c) {
  b -= a, c -= a;
  if (cross(b, c) > +EPS) return +1;
  if (cross(b, c) < -EPS) return -1;
  if (dot(b, c) < -EPS) return +2;
  if (norm(b) < norm(c)) return -2;
  return 0;
}

point crosspoint(const line& l, const line& m) {
  number A = cross(l.t - l.s, m.t - m.s);
  number B = cross(l.t - l.s, l.t - m.s);
  if (abs(A) < EPS && abs(B) < EPS) return m.s;  // same line
  if (abs(A) < EPS) assert(false);  // !!!PRECONDITION NOT SATISFIED!!!
  return m.s + B / A * (m.t - m.s);
}

polygon convex_cut(polygon& g, line& l) {
  polygon ret{};
  rep(i, g.size()) {
    auto a = g[i], b = g[(i + 1) % g.size()];
    if (ccw(l.s, l.t, a) != -1) ret.push_back(a);
    if (ccw(l.s, l.t, a) * ccw(l.s, l.t, b) < 0)
      ret.push_back(crosspoint(line{a, b}, l));
  }
  return ret;
}

bool compare(polygon& g, number V, number D, int ridx, number height) {
  line l{g[(ridx + 1) % g.size()], g[ridx]};
  point v = height * (l.t - l.s).nml() * point{0, -1};
  l.s = l.s + v, l.t = l.t + v;
  return convex_cut(g, l).area2() * D < V * 2;
}

int main() {
  int N;
  number D, V;
  while (cin >> N >> D >> V && (N || D || V)) {
    polygon g{};
    rep(i, N) {
      number x, y;
      cin >> x >> y;
      g.push_back(point{x, y});
    }

    number ans = 0;

    rep(i, N) {
      number l = 0, h = 114514;
      rep(_, 150) {
        number mid = (l + h) / 2;
        (compare(g, V, D, i, mid) ? l : h) = mid;
      }
      ans = max(ans, l);
    }

    printf("%.10f\n", ans);
  }
  return 0;
}