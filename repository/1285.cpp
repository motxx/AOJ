#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

int main() {
  for (int n, w; cin >> n >> w && n && w;) {
    int val[210] = {};
    int mx = 0;
    rep(i, n) {
      int x;
      cin >> x;
      val[x]++;
      mx = max(mx, x);
    }

    int imax = 0;
    for (int i = 0; i <= mx; i += w) {
      int cnt = 0;
      REP(j, i, i + w) { cnt += val[j]; }
      imax = max(imax, cnt);
    }

    double ink = 0.01;
    int hist = mx / w;
    for (int i = 0; i <= mx; i += w) {
      int cnt = 0;
      REP(j, i, i + w) { cnt += val[j]; }
      ink += (double)(hist - i / w) / hist * cnt / imax;
    }
    printf("%.10f\n", ink);
  }
  return 0;
}