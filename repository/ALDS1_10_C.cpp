#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int Tc;
  cin >> Tc;

  while (Tc--) {
    string s, t;
    cin >> s >> t;

    int dp[1001][1001] = {{}};

    int const N = s.size(), M = t.size();

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }

    cout << dp[N][M] << endl;
  }

  return 0;
}