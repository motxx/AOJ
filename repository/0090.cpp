#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef complex<double> P;

#define EPS (1e-8)

int main() {
  int n;
  while (cin >> n && n) {
    vector<P> c;
    for (int i = 0; i < n; i++) {
      double x, y;
      scanf("%lf,%lf", &x, &y);
      c.push_back(P(x, y));
    }

    vector<P> p;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (norm(c[i] - c[j]) <= 4.0 + EPS) {
          P cent = (c[i] + c[j]) / 2.0;
          double len = sqrt(1.0 - norm(c[i] - cent));
          double ang = arg(c[i] - c[j]);
          P p1 = cent + polar(len, ang + M_PI / 2);
          P p2 = cent + polar(len, ang - M_PI / 2);
          p.push_back(p1);
          p.push_back(p2);
        }
      }
    }

    int const N = p.size();
    int res = 1;
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++)
        if (norm(p[i] - c[j]) <= 1.0 + EPS) cnt++;
      res = max(res, cnt);
    }

    cout << res << endl;
  }

  return 0;
}