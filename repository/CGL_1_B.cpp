#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

#define EPS (1e-7)

double dot(P const& a, P const& b) { return real(conj(a) * b); }

double cross(P const& a, P const& b) { return imag(conj(a) * b); }

P projection_point(P const& a, P const& b, P const& c) {
  double k = dot(b - a, c - a) / norm(b - a);
  return a + k * (b - a);
}

P reflection_point(P const& a, P const& b, P const& c) {
  return c + 2. * (projection_point(a, b, c) - c);
}

int main() {
  P a, b;
  cin >> a.real() >> a.imag() >> b.real() >> b.imag();
  int q;
  cin >> q;
  for (; q--;) {
    P c;
    cin >> c.real() >> c.imag();
    P ans(reflection_point(a, b, c));
    printf("%.10f %.10f\n", ans.real(), ans.imag());
  }
  return 0;
}