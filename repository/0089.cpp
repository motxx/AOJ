#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int H, W[100];
int M[100][100];
int dp[100][100];

void input() {
  string str;

  while (getline(cin, str)) {
    replace(str.begin(), str.end(), ',', ' ');
    stringstream ss(str);
    while (ss >> M[H][W[H]]) W[H]++;
    H++;
    /*
    cout << H-1 << " " << W[H-1] << endl;
    for( int i=0; i<W[H-1]; i++ ) cout << M[H-1][i] << " ";
    cout << endl;
    */
  }
}

int solve() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W[i]; j++) {
      if (i - 1 < 0) {
        dp[i][j] = M[i][j];
        continue;
      }
      if (i <= H / 2 && j - 1 < 0) {
        dp[i][j] = dp[i - 1][j] + M[i][j];
        continue;
      }
      if (i <= H / 2 && j + 1 == W[i]) {
        dp[i][j] = dp[i - 1][j - 1] + M[i][j];
        continue;
      }
      if (i <= H / 2) {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + M[i][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + M[i][j];
      }
    }
  }

  /*
  for( int i=0; i<H; i++ ) {
    for( int j=0; j<W[i]; j++ ) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  */

  return dp[H - 1][0];
}

int main() {
  input();
  cout << solve() << endl;
  return 0;
}