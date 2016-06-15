#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1 << 29;

int main() {
  int n, m;
  while (cin >> n >> m && (n | m)) {
    vector<int> C(m);
    for (int i = 0; i < m; i++) cin >> C[i];

    vector<int> dp(256, INF);
    dp[128] = 0;
    while (n--) {
      vector<int> next(256, INF);
      int in;
      cin >> in;
      for (int i = 0; i <= 255; i++) {
        if (dp[i] < INF) {
          for (int j = 0; j < m; j++) {
            int now = i + C[j];
            if (now < 0) {
              now = 0;
            }
            if (now > 255) {
              now = 255;
            }
            int diff = (in - now) * (in - now);
            next[now] = min(next[now], dp[i] + diff);
          }
        }
      }
      dp = next;
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
  }
  return 0;
}