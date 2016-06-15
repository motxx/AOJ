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

// struct before_main{before_main(){cin.tie(0); ios::sync_with_stdio(false);}}
// before_main;

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

namespace point_2d {

using Real = double;

Real const EPS = 1e-7;  // !!! DO CHECK EPS !!!

typedef complex<Real> P;

bool operator<(P const& l, P const& r) {
  return abs(l.real() - r.real()) < EPS ? l.imag() < r.imag()
                                        : l.real() < r.real();
}

bool operator>(P const& l, P const& r) {
  return abs(l.real() - r.real()) < EPS ? l.imag() > r.imag()
                                        : l.real() > r.real();
}

struct Line : public pair<P, P> {
  Line(P const& a, P const& b) { first = a, second = b; }
  const P& operator[](int x) const { return x == 0 ? first : second; }
  P& operator[](int x) { return x == 0 ? first : second; }
};
typedef Line Segment;

struct Circle : public P {
  P& p = *this;
  Real r;
  Real (&cent)[2] = reinterpret_cast<Real (&)[2]>(*this);
  Circle() {}
  Circle(P const& p, Real r) : r(r) { this->p = p; }
};

Real cross(P const& a, P const& b) { return imag(conj(a) * b); }
Real dot(P const& a, P const& b) { return real(conj(a) * b); }
Real cos(P const& l, P const& r) {
  return dot(l, r) / (abs(l) * abs(r));
}  // not verified

enum ccw_result {
  counter_clockwise = +1,
  clockwise = -1,
  online_back = +2,
  online_front = -2,
  on_segment = 0
};

ccw_result ccw(P a, P b, P c) {
  b -= a, c -= a;
  if (cross(b, c) > 0) {
    return ccw_result::counter_clockwise;
  }
  if (cross(b, c) < 0) {
    return ccw_result::clockwise;
  }
  if (dot(b, c) < 0) {
    return ccw_result::online_back;
  }
  if (norm(b) < norm(c)) {
    return ccw_result::online_front;
  }
  return ccw_result::on_segment;
}

bool intersect_lp(Line const& l, P const& p) {
  return abs(cross(l[1] - p, l[0] - p)) < EPS;
}

bool intersect_sp(Line const& s, P const& p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) <
         EPS;  // triangle inequality
}

P projection(Line const& l, P const& p) {
  auto t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

Real distance_sp(Line const& s, P const& p) {
  P const r = projection(s, p);
  if (intersect_sp(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

Real distance_lp(Line const& l, P const& p) {
  return abs(p - projection(l, p));
}

Real instersect_cl(Circle const& c, Line const& l) {
  return distance_lp(l, c) <= c.r + EPS;
}

P crosspoint(const Line& l, const Line& m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
  if (abs(A) < EPS) assert(false);  // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

pair<P, P> crosspoint(Circle const& c, Line const& l) {
  auto h = projection(l, c);
  auto e = (l[1] - l[0]) / abs(l[1] - l[0]);
  auto base = sqrt(c.r * c.r - abs(h - c) * abs(h - c));
  return {h + e * base, h - e * base};
}

// ??????clang??§????????°???"(x, y)"?????¢?????????????????????????????????"x
// y"????????´??????
istream& operator>>(istream& is, P& p) {
  Real x, y;
  is >> x >> y;
  p = P(x, y);
  return is;
}
ostream& operator<<(ostream& os, Line& l) {
  return os << "{" << l[0] << ", " << l[1] << "}";
}
}
using namespace point_2d;

int main() {
  Circle c;
  cin >> c.p >> c.r;
  int n;
  cin >> n;
  rep(i, n) {
    P a, b;
    cin >> a >> b;
    auto cp = crosspoint(c, Line(a, b));
    if (cp.first > cp.second) {
      swap(cp.first, cp.second);
    }
    printf("%.10f %.10f %.10f %.10f\n", cp.first.real(), cp.first.imag(),
           cp.second.real(), cp.second.imag());
  }

  return 0;
}