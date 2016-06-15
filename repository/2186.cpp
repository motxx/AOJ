// Date: Sat Jun 08 13:09:40 JST 2013
#include <iostream>
using namespace std;
int mt[16][16][16][16];
int dp[16][16];
int i, j, k, l, m, n, o, a, b, c, d, cnt, X, Y;
void init() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      dp[i][j] = 0;
      for (int k = 0; k < 16; k++) {
        for (int l = 0; l < 16; l++) {
          mt[i][j][k][l] = 0;
        }
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int data = 0; data < n; data++) {
    init();
    cin >> X >> Y >> m;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c >> d;
      mt[a][b][c][d] = 1;
      mt[c][d][a][b] = 1;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= X; i++) {
      if (mt[i][0][i - 1][0] == 1) {
        dp[i][0] = 0;
      } else {
        dp[i][0] = dp[i - 1][0];
      }
    }

    for (int i = 1; i <= Y; i++) {
      if (mt[0][i][0][i - 1]) {
        dp[0][i] = 0;
      } else {
        dp[0][i] = dp[0][i - 1];
      }

      for (int j = 1; j <= X; j++) {
        if (mt[j][i][j - 1][i] == 0) {
          dp[j][i] += dp[j - 1][i];
        }
        if (mt[j][i][j][i - 1] == 0) {
          dp[j][i] += dp[j][i - 1];
        }
      }
    }
    if (dp[X][Y] == 0) {
      cout << "Miserable Hokusai!" << endl;
    } else {
      cout << dp[X][Y] << endl;
    }
  }
  return 0;
}