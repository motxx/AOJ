#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
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
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

template <class T, class U, class Compare>
void pair_sort(vector<T>& a, vector<U>& b, Compare comp) {
  vector<pair<T, U>> v;
  rep(i, a.size()) v.emplace_back(a[i], b[i]);
  sort(v.begin(), v.end(), comp);
  rep(i, a.size()) tie(a[i], b[i]) = v[i];
}
template <class T, class U>
void pair_sort(vector<T>& a, vector<U>& b) {
  pair_sort(a, b, std::less<pair<T, U>>());
}

typedef long long ll;
int const inf = 1e9;

int T, N;
int t[33];
int M[111];
int dp[111][33];

int solve() {
  rep(i, 111) rep(j, 33) dp[i][j] = inf;

  dp[0][T - 1] = 0;
  REP(i, 1, 101) {
    rep(j, T) {
      if (t[(j + 1) % T] <= M[i]) {
        minimize(dp[i][(j + 1) % T], dp[i - 1][j]);
        minimize(dp[i][T - 1], dp[i - 1][j] + 1);
      }
    }
  }

  return *min_element(dp[100], dp[100] + T);
}

int main() {
  for (; cin >> T && T;) {
    rep(i, T) cin >> t[i];
    cin >> N;
    rep(i, 111) M[i] = inf;
    rep(i, N) {
      int d, m;
      cin >> d >> m;
      minimize(M[d], m);
    }
    cout << solve() << endl;
  }

  return 0;
}