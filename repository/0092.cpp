#include <iostream>
using namespace std;

int main() {
  int i, j, n;
  int dp[1001][1001];
  int ma;
  char c;

  cin >> n;
  while (n != 0) {
    ma = 0;

    for (i = 0; i < n; i++) {
      dp[0][i] = 0;
    }
    for (i = 0; i < n; i++) {
      dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> c;
        if (c == '*') {
          dp[j][i] = 0;
          continue;
        }

        dp[j][i] = min(dp[j - 1][i], min(dp[j - 1][i - 1], dp[j][i - 1])) + 1;
        ma = (dp[j][i] > ma) ? dp[j][i] : ma;
      }
    }
    cout << ma << endl;

    cin >> n;
  }

  return 0;
}