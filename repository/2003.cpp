#include <assert.h>
#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<double, double> Pdd;

const double EPS = 1e-8;
const double INF = 1e12;
typedef complex<double> P;
namespace std {
bool operator<(const P& a, const P& b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
}
double cross(const P& a, const P& b) { return imag(conj(a) * b); }
double dot(const P& a, const P& b) { return real(conj(a) * b); }

struct L : public vector<P> {
  L(const P& a, const P& b) {
    push_back(a);
    push_back(b);
  }
};

typedef L Segment;

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return +1;    // counter clockwise
  if (cross(b, c) < 0) return -1;    // clockwise
  if (dot(b, c) < 0) return +2;      // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line
  return 0;
}

bool intersectSS(const Segment& s, const Segment& t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

P crosspoint(const L& l, const L& m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
  if (abs(A) < EPS) assert(false);  // !!!PRECONDITION NOT SATISFIED!!!
  return m[0] + B / A * (m[1] - m[0]);
}

int main() {
  int Tc;
  cin >> Tc;
  while (Tc--) {
    vector<pair<Pdd, int> > vec;
    double xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    Segment express(P(xa, ya), P(xb, yb));
    int N;
    cin >> N;
    int O, I;
    for (int i = 0; i < N; i++) {
      cin >> xa >> ya >> xb >> yb >> O >> I;
      Segment line(P(xa, ya), P(xb, yb));
      if (intersectSS(express, line)) {
        P crs = crosspoint(express, line);
        vec.push_back(make_pair(Pdd(crs.real(), crs.imag()), (O + I) % 2));
      }
    }

    sort(vec.begin(), vec.end());

    int ans = 1 << 29;
    for (int s = 0; s < 2; s++) {
      int cnt = 0, now = s;
      for (int i = 0; i < vec.size(); i++) {
        if (now == vec[i].second) {
          cnt++;
          now = 1 - now;
        }
      }
      ans = min(ans, cnt);
    }
    cout << ans << endl;
  }

  return 0;
}