#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, C;
  while (cin >> N >> C && N && C) {
    int panel[N];
    memset(panel, 0, sizeof panel);
    rep(i, N) rep(j, 16) {
      int x;
      cin >> x;
      if (x) {
        panel[i] += 1 << j;
      }
    }

    int jubi[C];
    memset(jubi, 0, sizeof jubi);
    rep(i, C) rep(j, 16) {
      int x;
      cin >> x;
      if (x) {
        jubi[i] += 1 << j;
      }
    }

    int dp[2][1 << 16];
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;

    int const mask = (1 << 16) - 1;
    rep(i, N) rep(S, 1 << 16) {
      if (dp[i & 1][S] == -1) continue;
      dp[(i + 1) & 1][panel[i] | S] =
          max(dp[(i + 1) & 1][panel[i] | S], dp[i & 1][S]);
      rep(j, C) {
        int nS = (panel[i] | S) & (mask - jubi[j]);
        int score = __builtin_popcount(panel[i] | S) - __builtin_popcount(nS);
        dp[(i + 1) & 1][nS] = max(dp[(i + 1) & 1][nS], dp[i & 1][S] + score);
      }
    }
    cout << *max_element(dp[N & 1], dp[N & 1] + (1 << 16)) << endl;
  }

  return 0;
}