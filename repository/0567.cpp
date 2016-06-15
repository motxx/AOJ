#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  double A, B, C, D[100];

  cin >> n >> A >> B >> C;

  for (int i = 0; i < n; i++) {
    cin >> D[i];
  }
  sort(D, D + n, greater<int>());

  double ret = 0;
  double dp[100];  // memo topping
  for (int i = 0; i < n - 1; i++) {
    D[i + 1] = D[i] + D[i + 1];
    dp[i + 1] = (C + D[i + 1]) / (A + (i + 2) * B);
    dp[i] = (C + D[i]) / (A + (i + 1) * B);
    ret = max(dp[i + 1], max(dp[i], max(ret, C / A)));
  }

  if (ret == 0)
    cout << (int)(C / A) << endl;
  else
    cout << (int)ret << endl;

  return 0;
}