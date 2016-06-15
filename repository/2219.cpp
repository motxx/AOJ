#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  for (int N, M; cin >> N >> M;) {
    int dp[3][330];
    int w[N];
    int v[N][3];
    for (int i = 0; i < N; i++) {
      string s;
      cin.ignore();
      getline(cin, s);
      cin >> w[i] >> v[i][0] >> v[i][1] >> v[i][2];
    }

    memset(dp, 0, sizeof dp);
    for (int k = 0; k < 3; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = w[i]; j <= M; j++) {
          dp[k][j] = max(dp[k][j], dp[k][j - w[i]] + v[i][k]);
        }
      }
    }

    cout << max(dp[0][M], max(dp[1][M], dp[2][M])) << endl;
  }

  return 0;
}