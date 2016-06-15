#include <iostream>
#include <string>
using namespace std;
const int inf = 1 << 23;
int main() {
  int h, w;
  while (cin >> h >> w && (h | w)) {
    string M[500];
    int dp[500][500] = {{}};

    for (int i = 0; i < h; i++) cin >> M[i];

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (M[i][j] == '.') {
          if (j)
            dp[i][j] = dp[i][j - 1] + 1;
          else
            dp[i][j] = 1;
        } else
          dp[i][j] = 0;
      }
    }

    int ans = 0;
    for (int j = 0; j < w; j++)
      for (int i = 0; i < h; i++) {
        int a = 0;
        int mn = inf;
        for (int k = i; k < h; k++) {
          mn = min(mn, dp[k][j]);
          a++;
          ans = max(ans, a * mn);
        }
      }
    cout << ans << endl;
  }
  return 0;
}