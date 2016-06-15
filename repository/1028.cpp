#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  //  cout << 5 * 100000 + 100000 + 5 * 10000 + 10000 + 5 * 1000 + 1000 << endl;

  while (1) {
    int P, N[7] = {};
    scanf("%d", &P);
    if (P == 0) break;
    REP(i, 1, 7) scanf("%d", &N[i]);

    int ans = 1000000000;

    REP(d, P, P + 100000) {
      int D = d;

      int U = 0;
      int k, m;

      m = D / 500;
      k = min(m, N[6]);
      D %= 500;
      D += (m - k) * 500;
      U += k;

      m = D / 100;
      k = min(m, N[5]);
      D %= 100;
      D += (m - k) * 100;
      U += k;

      m = D / 50;
      k = min(m, N[4]);
      D %= 50;
      D += (m - k) * 50;
      U += k;

      m = D / 10;
      k = min(m, N[3]);
      D %= 10;
      D += (m - k) * 10;
      U += k;

      m = D / 5;
      k = min(m, N[2]);
      D %= 5;
      D += (m - k) * 5;
      U += k;

      m = D;
      k = min(D, N[1]);
      D += (m - k);
      U += k;

      int T = d - P;
      int S = 0;
      S += T / 500;
      T %= 500;
      S += T / 100;
      T %= 100;
      S += T / 50;
      T %= 50;
      S += T / 10;
      T %= 10;
      S += T / 5;
      T %= 5;
      S += T;

      ans = min(ans, U + S);
    }
    printf("%d\n", ans);
  }

  return 0;
}