#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    int dp[35] = {1};
    for (int i = 0; i < N; i++) {
      dp[i + 1] += dp[i];
      dp[i + 2] += dp[i];
      dp[i + 3] += dp[i];
    }
    cout << dp[N] / 3650 + (dp[N] % 3650 ? 1 : 0) << endl;
  }

  return 0;
}