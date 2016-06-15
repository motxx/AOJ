#include <bits/stdc++.h>

using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
int main() {
  int a, b, c, d;
  int e, f, g, h;
  int Tc;
  while (cin >> Tc && Tc) {
    rep(_, Tc) {
      scanf("%d%d%d%d %d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
      int t[4][4];
      t[0][0] = a * e, t[0][1] = a * f, t[0][2] = a * g, t[0][3] = a * h;
      t[1][0] = b * e, t[1][1] = b * f, t[1][2] = b * g, t[1][3] = b * h;
      t[2][0] = c * e, t[2][1] = c * f, t[2][2] = c * g, t[2][3] = c * h;
      t[3][0] = d * e, t[3][1] = d * f, t[3][2] = d * g, t[3][3] = d * h;
      int ans[4] = {};
      ans[0] = t[0][0] - t[1][1] - t[2][2] - t[3][3];
      ans[1] = t[0][1] + t[1][0] + t[2][3] - t[3][2];
      ans[2] = t[0][2] + t[2][0] - t[1][3] + t[3][1];
      ans[3] = t[0][3] + t[1][2] - t[2][1] + t[3][0];
      rep(i, 4) {
        if (i) cout << " ";
        cout << ans[i];
      }
      cout << endl;
    }
  }
  return 0;
}