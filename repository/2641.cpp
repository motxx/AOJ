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

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

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

namespace point_3d {

using Real = long double;

Real const EPS = 1e-9;  // !!! DO CHECK EPS !!!

struct P3 {
  Real x, y, z;
  P3() : x(0), y(0), z(0) {}
  P3(Real x, Real y, Real z) : x(x), y(y), z(z){};
  P3 operator+(P3 const& r) const { return P3(x + r.x, y + r.y, z + r.z); }
  P3 operator-(P3 const& r) const { return P3(x - r.x, y - r.y, z - r.z); }
  P3 operator*(Real k) const { return P3(x * k, y * k, z * k); }
  P3 operator/(Real k) const { return P3(x / k, y / k, z / k); }
};

Real dot(P3 const& l, P3 const& r) { return l.x * r.x + l.y * r.y + l.z * r.z; }
P3 cross(P3 const& l, P3 const& r) {
  return P3(l.y * r.z - l.z * r.y, l.z * r.x - l.x * r.z,
            l.x * r.y - l.y * r.x);
}  // not verified

Real norm(P3 const& p) { return p.x * p.x + p.y * p.y + p.z * p.z; }
Real abs(P3 const& p) { return sqrt(p.x * p.x + p.y * p.y + p.z * p.z); }
Real cos(P3 const& l, P3 const& r) { return dot(l, r) / (abs(l) * abs(r)); }
Real angle(P3 const& l, P3 const& r) {
  return acos(cos(l, r));
}  // not verified

istream& operator>>(istream& is, P3& p) {
  Real x, y, z;
  is >> x >> y >> z;
  p = P3(x, y, z);
  return is;
}
ostream& operator<<(ostream& os, P3& p) {
  return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

struct Line : public pair<P3, P3> {
  P3 const& operator[](int idx) const { return idx == 0 ? first : second; }
  P3& operator[](int idx) { return idx == 0 ? first : second; }
};
typedef Line Segment;

Real distance_lp(Line const& l, P3 const& p) {  // not verified
  return abs(p - l[0]) * sin(angle(l[1] - l[0], p - l[0]));
}

P3 projection(Line const& l, P3 const& p) {
  Real t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + (l[0] - l[1]) * t;
}

bool intersect_sp(Segment const& s, P3 const& p) {
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) <
         EPS;  // triangle inequality
}

Real distance_sp(Segment const& s, P3 const& p) {
  P3 const r = projection(s, p);
  if (intersect_sp(s, r))
    return abs(r - p);  // ?°???±?????????????????????????????????
  return min(abs(s[0] - p), abs(s[1] - p));
}
}
using namespace point_3d;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<tuple<P3, Real, ll>> os;
  rep(i, N) {
    P3 p;
    Real r;
    ll l;
    cin >> p >> r >> l;
    os.emplace_back(p, r, l);
  }

  rep(_, Q) {
    ll ans = 0;
    Segment beam;
    cin >> beam[0] >> beam[1];

    auto intersect_segment_sphere = [&](int oidx) {
      P3 c;
      Real r;
      ll _;
      tie(c, r, _) = os[oidx];
      return distance_sp(beam, c) <= r + EPS;
    };

    rep(i, N) {
      if (intersect_segment_sphere(i)) {
        ans += get<2>(os[i]);
      }
    }
    cout << ans << endl;
  }

  return 0;
}