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
double const EPS = 1e-9;

typedef double Real;
typedef complex<Real> P;
typedef vector<P> line;

struct circle {
  P p;
  Real r;
};

double sq(double x) { return x * x; }

bool out(circle& a, circle& b) {
  return abs(a.p - b.p) > a.r + b.r;  // + EPS;
}

bool is_intersect(circle& a, circle& b) {
  return abs(a.p - b.p) <= a.r + b.r &&
         abs(a.p - b.p) + min(a.r, b.r) >= max(a.r, b.r);
}

bool contains(circle& a, circle& b) {
  return abs(a.p - b.p) + min(a.r, b.r) < max(a.r, b.r);
}

bool contains(circle& c, P& p) { return abs(c.p - p) <= c.r + EPS; }

Real cross(P const& a, P const& b) { return imag(conj(a) * b); }

bool is_parallel(line const& l, line const& m) {
  return abs(cross(l[1] - l[0], m[1] - m[0])) < EPS;
}

P crosspoint(line const& l, line const& m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
  if (abs(A) < EPS) assert(false && "PRECONDITION NOT SATISFIED");
  return m[0] + B / A * (m[1] - m[0]);
}

pair<P, P> crosspoint(circle c1, circle c2) {
  if (c1.p.real() > c2.p.real()) swap(c1, c2);
  Real const d = abs(c2.p - c1.p);
  Real const alpha = acos((c2.p.real() - c1.p.real()) / d) *
                     ((c1.p.imag() > c2.p.imag()) ? -1.0 : 1.0);
  Real const beta = acos((c1.r * c1.r - c2.r * c2.r + d * d) / 2.0 / d / c1.r);
  return make_pair(c1.p + polar(c1.r, alpha - beta),
                   c1.p + polar(c1.r, alpha + beta));
}

int N;
double x[11], y[11], l[11];

bool compare(double h) {
  vector<circle> cs;
  rep(i, N) {
    if (l[i] < h - EPS) return false;
    cs.push_back({{x[i], y[i]}, sqrt(sq(l[i]) - sq(h))});
  }
  rep(i, N) REP(j, i + 1, N) {
    if (out(cs[i], cs[j])) return false;
  }

  rep(i, N) REP(j, i + 1, N) REP(k, j + 1, N) {
    if (contains(cs[i], cs[j]) || contains(cs[j], cs[k]) ||
        contains(cs[k], cs[i]))
      continue;
    auto p = crosspoint(cs[i], cs[j]);
    auto q = crosspoint(cs[j], cs[k]);
    auto r = crosspoint(cs[k], cs[i]);
    if (!contains(cs[k], p.first) && !contains(cs[k], p.second) &&
        !contains(cs[i], q.first) && !contains(cs[i], q.second) &&
        !contains(cs[j], r.first) && !contains(cs[j], r.second))
      return false;
  }

  return true;
}

double solve() {
  double l = 0.0, r = 1e10;
  rep(_, 150) {
    double m = (l + r) / 2.0;
    (compare(m) ? l : r) = m;
  }
  return l;
}

int main() {
  for (; cin >> N && N;) {
    rep(i, N) { cin >> x[i] >> y[i] >> l[i]; }
    printf("%.10f\n", solve());
  }

  return 0;
}