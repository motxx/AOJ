#include <complex>
#include <iostream>

using namespace std;
typedef complex<double> P;

#define EPS (1e-5)

struct Seg {
  P s, t;
  Seg(P s, P t) : s(s), t(t) {}
};

double cross(P a, P b) { return (a.real() * b.imag() - a.imag() * b.real()); }

bool isIntersectedSS(Seg a, Seg b) {
  return (cross(a.t - a.s, b.s - a.s) * cross(a.t - a.s, b.t - a.s) < EPS) &&
         (cross(b.t - b.s, a.s - b.s) * cross(b.t - b.s, a.t - b.s) < EPS);
}

int main() {
  int n;
  cin >> n;
  for (int I = 0; I < n; I++) {
    int x, y;
    cin >> x >> y;
    P pt1(x, y);
    cin >> x >> y;
    P pt2(x, y);
    cin >> x >> y;
    P pt3(x, y);
    cin >> x >> y;
    P pk(x, y);
    cin >> x >> y;
    P ps(x, y);

    int ok = 0;
    ok += isIntersectedSS(Seg(pt1, pt2), Seg(pk, ps));
    ok += isIntersectedSS(Seg(pt2, pt3), Seg(pk, ps));
    ok += isIntersectedSS(Seg(pt3, pt1), Seg(pk, ps));

    if (ok % 2) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }
  return 0;
}