#include <bits/stdc++.h>

using namespace std;

int const INF = 1 << 28;

int main() {
  int N;
  while (cin >> N && N) {
    vector<vector<int> > vec(N, vector<int>(N + 1));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N + 1; j++) cin >> vec[i][j];

    vector<int> dp(1 << N, INF);
    dp[0] = 0;
    for (int S = 0; S < (1 << N); S++) {
      for (int i = 0; i < N; i++) {
        if (S >> i & 1) continue;
        dp[S + (1 << i)] = min(dp[S + (1 << i)], dp[S] + vec[i][0]);
        for (int j = 0; j < N; j++) {
          if (!(S >> j & 1)) continue;
          dp[S + (1 << i)] = min(dp[S + (1 << i)], dp[S] + vec[i][j + 1]);
        }
      }
    }

    cout << dp[(1 << N) - 1] << endl;
  }
  return 0;
}