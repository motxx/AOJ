#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;
struct Line : public vector<P> {
  Line(P a = P(), P b = P()) {
    push_back(a);
    push_back(b);
  }
};
typedef Line Segment;

#define EPS (1e-7)

bool operator<(P const& a, P const& b) {
  return (a.real() != a.real()) ? a.real() < b.real() : a.imag() < b.imag();
}

double dot(P const& a, P const& b) { return real(conj(a) * b); }

double cross(P const& a, P const& b) { return imag(conj(a) * b); }

P projection_point(P const& a, P const& b, P const& c) {
  double k = dot(b - a, c - a) / norm(b - a);
  return a + k * (b - a);
}

P reflection_point(P const& a, P const& b, P const& c) {
  return c + 2. * (projection_point(a, b, c) - c);
}

bool is_parallel(Segment const& s, Segment const& t) {
  return abs(cross(s[1] - s[0], t[1] - t[0])) < EPS;
}

bool is_orthogonal(Segment const& s, Segment const& t) {
  return abs(dot(s[1] - s[0], t[1] - t[0])) < EPS;
}

int ccw(P a, P b, P c) {
  b -= a, c -= a;
  if (cross(b, c) > 0) return +1;    // counter clockwise
  if (cross(b, c) < 0) return -1;    // clockwise
  if (dot(b, c) < 0) return +2;      // c-a-b
  if (norm(b) < norm(c)) return -2;  // a-b-c
  return 0;                          // on segment
}

bool is_intersect_ss(Segment s, Segment t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

int main() {
  int q;
  cin >> q;
  for (; q--;) {
    Segment s, t;
    cin >> s[0].real() >> s[0].imag();
    cin >> s[1].real() >> s[1].imag();
    cin >> t[0].real() >> t[0].imag();
    cin >> t[1].real() >> t[1].imag();

    cout << is_intersect_ss(s, t) << endl;
  }

  return 0;
}