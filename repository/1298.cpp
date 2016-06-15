#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

namespace std {
bool operator<(P const& a, P const& b) {
  if (real(a) != real(b)) return real(a) < real(b);
  return imag(a) < imag(b);
}
}

double const EPS = 1e-8;

#define prev(G, i) (G[((i - 1) + G.size()) % G.size()])
#define curr(G, i) (G[i % G.size()])
#define next(G, i) (G[(i + 1) % G.size()])

double dot(P const& a, P const& b) { return real(conj(a) * b); }

double cross(P const& a, P const& b) { return imag(conj(a) * b); }

typedef vector<P> Polygon;

enum {
  counter_clock_wise = +1,
  clockwise = -1,
  cab_online = +2,
  abc_online = -2,
  on_segment = 0
};
int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return counter_clock_wise;
  if (cross(b, c) < 0) return clockwise;
  if (dot(b, c) < 0) return cab_online;
  if (norm(b) < norm(c)) return abc_online;
  return on_segment;
}

Polygon convex_hull(vector<P> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2 * n);
  for (int i = 0; i < n; ch[k++] = ps[i++])  // lower-hull
    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])  // upper-hull
    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
  ch.resize(k - 1);
  return ch;
}

struct Line : public vector<P> {
  Line(P const& a, P const& b) { push_back(a), push_back(b); }
};

typedef Line Segment;

bool is_intersect_ss(Segment const& s, Segment const& t) {
  return (ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) < EPS) &&
         (ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) < EPS);
}

// contain: 2, on segment: 1, the other case: 0
int contains(Polygon const& G, P const& p) {
  bool x = false;
  for (int i = 0; i < (int)G.size(); i++) {
    P v1 = curr(G, i) - p, v2 = next(G, i) - p;
    if (v1.imag() > v2.imag()) swap(v1, v2);
    if (v1.imag() <= 0 && 0 < v2.imag() && cross(v1, v2) > 0) x = !x;
    if (cross(v1, v2) == 0 && dot(v1, v2) <= 0) return 1;
  }
  return (x ? 2 : 0);
}

int main() {
  int N, M;
  while (cin >> N >> M && (N | M)) {
    Polygon G1(N), G2(M);
    rep(i, N) cin >> G1[i].real() >> G1[i].imag();
    rep(i, M) cin >> G2[i].real() >> G2[i].imag();

    G1 = convex_hull(G1);
    N = G1.size();
    G2 = convex_hull(G2);
    M = G2.size();
    //    cout << "convex hull\n";
    bool ok = (!contains(G1, G2[0])) && (!contains(G2, G1[0]));
    rep(i, N) {
      rep(j, M) {
        Segment s1 = Segment(curr(G1, i), next(G1, i));
        Segment s2 = Segment(curr(G2, j), next(G2, j));
        if (is_intersect_ss(s1, s2)) {
          ok = 0;
        }
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }

  return 0;
}