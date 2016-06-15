#include <iostream>

using namespace std;

long long dp[18][301];

int main() {
  for (int i = 1; i <= 17; i++) {
    for (int j = 0; j <= 300; j++) {
      if (i == 1) {
        if (j == 0)
          dp[1][0] = 1;
        else
          dp[i][j] = 1;
      } else if (j == 0)
        dp[i][j] = 1;
      else {
        dp[i][j] = dp[i - 1][j];
        if (j - i * i >= 0) dp[i][j] += dp[i][j - i * i];
      }
    }
  }
  /*
  for(int i=0; i<=17; i++) {
    for(int j=0; j<=19; j++) printf("%3lld", dp[i][j]);
    cout << endl;
  }

  for(int i=0; i<=17; i++) {
    for(int j=20; j<=30; j++) printf("%3lld", dp[i][j]);
    cout << endl;
  }
  */

  int n;

  while (cin >> n, n) {
    cout << dp[17][n] << endl;
  }

  return 0;
}