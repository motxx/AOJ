#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;
typedef vector<P> Polygon;

double dot(P const& a, P const& b) { return real(conj(a) * b); }
double cross(P const& a, P const& b) { return imag(conj(a) * b); }

#define prev(G, i) (G[(i - 1 + G.size()) % G.size()])
#define curr(G, i) (G[i])
#define next(G, i) (G[(i + 1) % G.size()])

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
  int N;
  cin >> N;
  Polygon G;
  rep(i, N) {
    double x, y;
    cin >> x >> y;
    G.push_back(P(x, y));
  }
  int Q;
  cin >> Q;
  rep(i, Q) {
    P p;
    cin >> p.real() >> p.imag();
    cout << contains(G, p) << endl;
  }

  return 0;
}