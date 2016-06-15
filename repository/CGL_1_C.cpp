#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

#define EPS (1e-7)

bool operator<(P const& a, P const& b) {
  return (a.real() != a.real()) ? a.real() < b.real() : a.imag() < b.imag();
}

double dot(P const& a, P const& b) { return real(conj(a) * b); }

double cross(P const& a, P const& b) { return imag(conj(a) * b); }

int ccw(P a, P b, P c) {
  b -= a, c -= a;
  if (cross(b, c) > 0) return +1;    // counter clockwise
  if (cross(b, c) < 0) return -1;    // clockwise
  if (dot(b, c) < 0) return +2;      // c-a-b
  if (norm(b) < norm(c)) return -2;  // a-b-c
  return 0;                          // on segment
}

int main() {
  P p0, p1;
  cin >> p0.real() >> p0.imag() >> p1.real() >> p1.imag();
  int q;
  cin >> q;
  rep(i, q) {
    P p3;
    cin >> p3.real() >> p3.imag();
    int ret = ccw(p0, p1, p3);
    if (ret == +1) cout << "COUNTER_CLOCKWISE\n";
    if (ret == -1) cout << "CLOCKWISE\n";
    if (ret == +2) cout << "ONLINE_BACK\n";
    if (ret == -2) cout << "ONLINE_FRONT\n";
    if (ret == 0) cout << "ON_SEGMENT\n";
  }

  return 0;
}