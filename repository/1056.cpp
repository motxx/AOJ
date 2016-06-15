#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  vector<vector<double>> dp(100011, vector<double>(22));
  vector<double> dp2(100001);
  dp[1][1] = 1;

  REP(i, 1, 100001) {
    rep(j, 20) {
      dp[i + 1][j + 1] = dp[i][j] * pow(0.5, j);
      dp[i + 1][0] += dp[i][j] * (1.0 - pow(0.5, j));
    }
  }

  rep(i, 100001) {
    double sum = 0.0;
    REP(j, 1, 20) sum += dp[i + 1][j];
    dp2[i + 1] = sum + dp2[i];
  }

  int n;
  while (cin >> n && n) printf("%.10f\n", dp2[n]);

  return 0;
}