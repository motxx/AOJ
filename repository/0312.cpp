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

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

int sumw[200001], sumt[200001];
int c[15], b[15];

int main() {
  int M, N;
  cin >> M >> N;
  rep(i, M) {
    scanf("%d%d", &sumw[i + 1], &sumt[i + 1]);
    sumw[i + 1] += sumw[i];
    sumt[i + 1] += sumt[i];
  }
  rep(i, N) { cin >> c[i] >> b[i]; }

  int dp[1 << N];
  zero(dp);

  rep(S, 1 << N) {
    rep(i, N) {
      if (S >> i & 1) {
        continue;
      }
      int k = upper_bound(sumw + dp[S], sumw + M + 1, c[i] + sumw[dp[S]]) -
              sumw - 1;
      int l = upper_bound(sumt + dp[S], sumt + M + 1, b[i] + sumt[dp[S]]) -
              sumt - 1;
      dp[S | (1 << i)] = max(dp[S | (1 << i)], min(k, l));
    }
  }

  cout << dp[(1 << N) - 1] << endl;

  return 0;
}