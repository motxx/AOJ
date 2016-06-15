#include <bits/stdc++.h>

using namespace std;
typedef complex<double> P;
typedef vector<P> Polygon;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

#define prev(G, i) (G[(i - 1 + G.size()) % G.size()])
#define curr(G, i) (G[i])
#define next(G, i) (G[(i + 1) % G.size()])

double dot(P const& a, P const& b) { return real(conj(a) * b); }
double cross(P const& a, P const& b) { return imag(conj(a) * b); }

enum { counter_clock_wise, clockwise, cab_online, abc_online };
int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return counter_clock_wise;
  if (cross(b, c) < 0) return clockwise;
  if (dot(b, c) < 0) return cab_online;
  if (norm(b) < norm(c)) return abc_online;
  return 0;
}

bool is_convex(Polygon const& G) {
  for (int i = 0; i < (int)G.size(); i++)
    if (ccw(prev(G, i), curr(G, i), next(G, i)) == clockwise) {
      return false;
    }
  return true;
}

int main() {
  int N;
  cin >> N;
  Polygon G(N);
  rep(i, N) cin >> G[i].real() >> G[i].imag();
  cout << is_convex(G) << endl;

  return 0;
}