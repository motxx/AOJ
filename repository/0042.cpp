
#include <climits>
#include <iostream>
using namespace std;

int main(void) {
  int dp[1001][1001];  // [takara][weight]
  int wei[1001];       // [takara]
  int val[1001];       // [takara]
  int i, w;
  int n, tw;
  int datcnt;
  char c;

  cin >> tw;
  for (datcnt = 1; tw != 0; datcnt++) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> val[i];
      cin >> c;
      cin >> wei[i];
    }

    // initArrayDP
    for (i = 0; i <= n; i++) {
      for (w = 0; w <= tw; w++) {
        dp[i][w] = 0;
      }
    }
    // cout << "--map";
    for (i = 1; i <= n; i++) {
      for (w = 1; w <= tw; w++) {
        int tem = w - wei[i];
        if (tem < 0) {
          dp[i][w] = dp[i - 1][w];
        } else {
          dp[i][w] = max(dp[i - 1][w], dp[i - 1][tem] + val[i]);
        }
      }
    }

    // for(i = 1; i <= n; i++) {
    //  for(w = 1; w <= tw; w++) {
    //	printf("%5d", dp[i][w]);
    //  }
    //  printf("\n");
    //}

    // [takara]の最終列から価値最大かつ、そのなかで重さ最初を探す。
    int maxval = INT_MIN;
    int lastwei = INT_MAX;

    for (w = 0; w <= tw; w++) maxval = max(dp[n][w], maxval);

    for (w = tw; w >= 0; w--)
      if (dp[n][w] == maxval) lastwei = min(lastwei, w);

    cout << "Case " << datcnt << ":" << endl;
    cout << maxval << endl << lastwei << endl;

    cin >> tw;
  }
  return 0;
}