#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;
typedef vector<P> Polygon;

double const EPS = 1e-7;
double const inf = 1e10;

struct Line : public vector<P> {
  Line() {}
  Line(P const& a, P const& b) { push_back(a), push_back(b); }
  P vectorize() { return (*this)[1] - (*this)[0]; }
  double length() { return abs((*this)[1] - (*this)[0]); }
};

inline double dot(P const& a, P const& b) { return real(conj(a) * b); }
inline double cross(P const& a, P const& b) { return imag(conj(a) * b); }

enum {
  counter_clockwise = +1,
  clockwise = -1,
  cab_online = +2,
  abc_online = -2,
  on_segment = 0
};
int ccw(P a, P b, P c) {
  b -= a, c -= a;
  if (cross(b, c) > 0) return counter_clockwise;
  if (cross(b, c) < 0) return clockwise;
  if (dot(b, c) < 0) return cab_online;
  if (norm(b) < norm(c)) return abc_online;
  return on_segment;
}

typedef Line Segment;

P crosspoint(Line const& l, Line const& m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) {
    return m[0];
  }  // same line
  if (abs(A) < EPS) {
    return P(inf, inf);
  }
  return m[0] + B / A * (m[1] - m[0]);
}

// Notice: Return left part of the polygon.
Polygon convex_cut(Polygon const& G, Line const& l) {
  Polygon left_part;
  rep(i, G.size()) {
    P const &a = G[i], b = G[(i + 1) % G.size()];
    Line const& ab = Line(a, b);
    if (ccw(l[0], l[1], a) != clockwise) {
      left_part.push_back(a);
    }
    if (ccw(l[0], l[1], a) * ccw(l[0], l[1], b) < 0) {
      P r = crosspoint(ab, l);
      if (r == P(inf, inf)) {
        continue;
      }
      left_part.push_back(r);
    }
  }
  return left_part;
}

// Notice: The border of the polygon in counterclockwise order.
bool able_polygon(Polygon const& G, double x) {
  int N = G.size();
  Polygon A = {{-inf, -inf}, {inf, -inf}, {inf, inf}, {-inf, inf}};
  rep(i, N) {
    Line ln(G[i], G[(i + 1) % N]);
    P shift = ln.vectorize() * polar(x / ln.length(), M_PI / 2.);
    A = convex_cut(A, Line(G[i] + shift, G[(i + 1) % G.size()] + shift));
  }
  return !A.empty();
}

double solve(Polygon const& G) {
  double L = 0., R = inf;
  rep(loop, 1000) {
    double M = (L + R) / 2.;
    if (able_polygon(G, M)) {
      L = M;
    } else {
      R = M;
    }
  }
  return L;
}

int main() {
  int N;
  while (cin >> N && N) {
    Polygon G(N);
    rep(i, N) {
      double x, y;
      cin >> x >> y;
      G[i] = P(x, y);
    }
    printf("%.8f\n", solve(G));
  }
  return 0;
}