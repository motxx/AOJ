#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define zero(a) memset(a, 0, sizeof a)

int N, T, L, B;
int F[101];

void solve() {
  static double dp[2][101][2];
  rep(i, 2) rep(j, 101) rep(k, 2) dp[i][j][k] = 0;
  dp[0][0][0] = 1.0;
  rep(i, T) {
    rep(j, 101) rep(k, 2) dp[(i + 1) & 1][j][k] = 0;
    rep(pos, N - 1) rep(skip, 2) {
      if (F[pos] == 1 && skip == 1) {
        dp[(i + 1) & 1][pos][0] += dp[i & 1][pos][1];
      } else {
        REP(dice, 1, 7) {
          int npos = pos + dice;
          if (npos > N - 1) {
            npos = 2 * (N - 1) - npos;
          }
          if (npos < 0) {
            npos *= -1;
          }
          if (F[npos] == 2) {
            npos = 0;
          }
          int nskip = F[npos] == 1;
          dp[(i + 1) & 1][npos][nskip] += dp[i & 1][pos][skip] / 6;
        }
      }
    }
    dp[(i + 1) & 1][N - 1][0] += dp[i & 1][N - 1][0];
  }

  printf("%.15f\n", dp[T & 1][N - 1][0]);
}

int main() {
  for (; cin >> N >> T >> L >> B && (N | T | L | B);) {
    N++;
    zero(F);
    rep(i, L) {
      int pos;
      cin >> pos;
      F[pos] = 1;
    }
    rep(i, B) {
      int pos;
      cin >> pos;
      F[pos] = 2;
    }
    solve();
  }
  return 0;
}