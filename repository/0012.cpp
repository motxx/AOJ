#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
typedef complex<double> P;
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
  P ps[4];
  while (1) {
    rep(i, 4) { cin >> ps[i].real() >> ps[i].imag(); }
    if (cin.eof()) break;
    int sum = 0;
    rep(i, 3) { sum += ccw(ps[i], ps[(i + 1) % 3], ps[3]); }
    if (sum == 3 || sum == -3)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}