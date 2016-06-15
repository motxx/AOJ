#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, M;
  while (cin >> N >> M && (N | M)) {
    vector<vector<double> > p(N, vector<double>(N, 0));
    rep(i, N) rep(j, N) cin >> p[i][j];
    vector<vector<double> > dp(M, vector<double>(N, 0));
    rep(i, N) dp[0][i] = 1.0;
    REP(k, 1, M)
    rep(i, N) rep(j, N) dp[k][j] = max(dp[k][j], dp[k - 1][i] * p[i][j]);

    double res = 0.;
    rep(i, N) res = max(res, dp[M - 1][i]);

    printf("%.2f\n", res);
  }

  return 0;
}