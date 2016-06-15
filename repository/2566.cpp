#include <assert.h>
#include <algorithm>
#include <array>
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

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
constexpr int MOD = 1e9 + 7;

string a, b, c;
ll dp[51][3];

int main() {
  while (cin >> a) {
    if (a == "0") break;
    cin >> b >> c;
    reverse(all(a));
    reverse(all(b));
    reverse(all(c));
    int n = a.size();
    vector<vector<int>> va(n), vb(n), vc(n);
    rep(i, n) {
      if (a[i] == '?')
        REP(k, i == n - 1, 10) va[i].push_back(k);
      else
        va[i].push_back(a[i] - '0');

      if (b[i] == '?')
        REP(k, i == n - 1, 10) vb[i].push_back(k);
      else
        vb[i].push_back(b[i] - '0');

      if (c[i] == '?')
        REP(k, i == n - 1, 10) vc[i].push_back(k);
      else
        vc[i].push_back(c[i] - '0');
    }

    zero(dp);
    dp[0][0] = 1;

    rep(i, n) rep(carry, 3) {
      for (auto& da : va[i])
        for (auto& db : vb[i])
          for (auto& dc : vc[i]) {
            int num = (da + db + carry) % 10;
            int ncr = (da + db + carry) / 10;
            if (num == dc) {
              dp[i + 1][ncr] += dp[i][carry];
              dp[i + 1][ncr] %= MOD;
            }
          }
    }

    cout << dp[n][0] << endl;
  }

  return 0;
}