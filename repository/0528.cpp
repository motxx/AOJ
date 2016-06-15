#include <algorithm>
#include <iostream>
using namespace std;

int dp[4002][4002];

int main() {
  string s;
  string t;
  int mx;

  while (getline(cin, s)) {
    fill(dp[0], dp[4000] + 4000, 0);
    getline(cin, t);
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = 0;
        }
      }
    }

    mx = 0;
    for (int i = 0; i <= n + 1; i++)
      for (int j = 0; j <= m + 1; j++) mx = max(mx, dp[i][j]);

    cout << mx << endl;
  }

  return 0;
}