#include <algorithm>
#include <array>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a)                                                               \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2> inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2> inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

int N;
int a[100010];
int dp[100010];

int main() {

  cin >> N;
  rep(i, N) { cin >> a[i]; }

  int x = 0;
  rep(i, N) {
    x--;
    if (a[i] == 0)
      x = inf;
    if (a[i] < 0)
      minimize(x, -a[i]);
    maximize(dp[i], x);
  }

  x = 0;
  for (int i = N - 1; i >= 0; i--) {
    x--;
    if (!a[i])
      x = inf;
    if (a[i] < 0)
      minimize(x, -a[i]);
    maximize(dp[i], x);
  }

  int ans = 0;
  rep(i, N) {
    if (a[i] > 0)
      ans += min(dp[i], a[i]);
  }

  cout << ans << endl;

  return 0;
}