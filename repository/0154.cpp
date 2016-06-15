#include <algorithm>
#include <iostream>
using namespace std;

int a[11];
int b[11];
int dp
    [11]
    [1010];  // xﾃ､ﾂｻﾂ･ﾃ､ﾂｸﾂ凝｣ﾂ?ｮﾃ｣ﾂつｫﾃ｣ﾂδｼﾃ｣ﾂδ嘉｣ﾂ?ｮﾃ｣ﾂ?ｿﾃ｣ﾂつ津ｧﾂ板ｨﾃ｣ﾂ??｣ﾂ?ｦﾃｦﾂ閉ｰyﾃ｣ﾂ?ｫﾃ｣ﾂ?ｪﾃ｣ﾂつ凝｣ﾂδ妥｣ﾂつｿﾃ｣ﾂδｼﾃ｣ﾂδｳﾃｦﾂ閉ｰ

int main() {
  int m;

  while (cin >> m && m) {
    for (int i = 0; i < m; i++) {
      cin >> a[i] >> b[i];
    }

    fill(dp[0], dp[8], 0);
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < 1001; j++) {
        if (dp[i][j]) {
          for (int k = 0; k <= b[i]; k++) {
            if (j + k * a[i] <= 1000) dp[i + 1][j + k * a[i]] += dp[i][j];
          }
        }
      }
    }

    int g;
    cin >> g;
    for (int i = 0; i < g; i++) {
      int q;
      cin >> q;
      cout << dp[m][q] << endl;
    }
  }

  return 0;
}