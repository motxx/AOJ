#include <assert.h>
#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

#define EPS (1e-7)

typedef complex<double> P;
struct Line : public vector<P> {
  Line() {}
  Line(P a, P b) {
    push_back(a);
    push_back(b);
  }
};

double cross(P const& a, P const& b) { return imag(conj(a) * b); }

bool is_cross_ss(Line const& a, Line const& b) {
  return (cross(a[1] - a[0], b[0] - a[0]) * cross(a[1] - a[0], b[1] - a[0]) <
          EPS) &&
         (cross(b[1] - b[0], a[0] - b[0]) * cross(b[1] - b[0], a[1] - b[0]) <
          EPS);
}

P crosspoint_ss(Line const& a, Line const& b) {
  P vb = b[1] - b[0];
  double d1 = abs(cross(vb, a[0] - b[0]));
  double d2 = abs(cross(vb, a[1] - b[0]));
  double t = d1 / (d1 + d2);
  return a[0] + (a[1] - a[0]) * t;
}

bool operator==(P const& a, P const& b) {
  return (abs(a.real() - b.real()) < EPS && abs(a.imag() - b.imag()) < EPS);
}

int main() {
  while (1) {
    Line l[3];
    rep(i, 3) {
      double sx, sy, gx, gy;
      cin >> sx >> sy >> gx >> gy;
      if (i == 0 && sx == 0 && sy == 0 && gx == 0 && gy == 0) return 0;
      l[i] = Line(P(sx, sy), P(gx, gy));
    }

    vector<P> ps;
    rep(i, 3) {
      if (is_cross_ss(l[i], l[(i + 1) % 3])) {
        P cp = crosspoint_ss(l[i], l[(i + 1) % 3]);
        bool ok = 1;
        rep(j, (int)ps.size()) if (ps[j] == cp) { ok = 0; }
        if (ok) {
          ps.push_back(cp);
        }
      }
    }

    if (ps.size() < 3) {
      cout << "kyo\n";
      continue;
    }
    if (ps.size() > 3) {
      assert(false && "sine");
    }

    double ans = abs(cross(ps[2] - ps[0], ps[1] - ps[0])) / 2.;
    if (ans >= 1900000.) {
      cout << "dai-kichi\n";
    } else if (ans >= 1000000.) {
      cout << "chu-kichi\n";
    } else if (ans >= 100000.) {
      cout << "kichi\n";
    } else if (ans > EPS) {
      cout << "syo-kichi\n";
    } else {
      cout << "kyo\n";
    }
  }

  return 0;
}