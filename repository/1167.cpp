#include <bits/stdc++.h>

using namespace std;

int dp1[1000001];
int dp2[1000001];

int const INF = 1 << 29;

int main() {
  fill(dp1, dp1 + 1000001, INF);
  fill(dp2, dp1 + 1000001, INF);

  dp1[0] = dp2[0] = 0;

  for (int i = 1;; i++) {
    int n = i * (i + 1) * (i + 2) / 6;
    if (n > 1000000) break;
    for (int j = n; j <= 1000000; j++) {
      dp1[j] = min(dp1[j], dp1[j - n] + 1);
      if (n % 2) {
        dp2[j] = min(dp2[j], dp2[j - n] + 1);
      }
    }
  }

  int N;
  while (cin >> N && N) {
    cout << dp1[N] << ' ' << dp2[N] << endl;
  }
  return 0;
}