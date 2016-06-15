#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int f(int n) {
  int ret = n;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ret -= ret / i;
      while (n % i == 0) n /= i;
    }
  }
  if (n != 1) ret -= ret / n;

  return ret;
}

int main() {
  int tc, n;
  long long dp[1000001];

  dp[1] = 2;
  for (int i = 1; i < 1000000; i++) dp[i + 1] = dp[i] + f(i + 1);

  cin >> tc;
  while (tc--) {
    cin >> n;
    cout << dp[n] << endl;
  }
  return 0;
}