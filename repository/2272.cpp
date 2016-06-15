#include <iostream>
using namespace std;

int main() {
  int h, w;
  int c;
  int dp[50][50];
  char ch;

  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> ch;
      c = ch - '0';
      if (i == 0 && j == 0) {
        dp[i][j] = c;
      } else {
        if (i == 0)
          dp[i][j] = dp[i][j - 1] + c;
        else if (j == 0)
          dp[i][j] = dp[i - 1][j] + c;
        else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + c;
        }
      }
    }
  }
  cout << dp[h - 1][w - 1] << endl;

  return 0;
}