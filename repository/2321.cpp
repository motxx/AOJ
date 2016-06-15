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

ll solve(int N) {
  static ll dp[2][1 << 16];
  zero(dp);

  rep(i, N) {
    int M;
    ll L;
    scanf("%d%lld", &M, &L);

    int bit = 0;
    rep(_, M) {
      int s, t;
      cin >> s >> t;
      s -= 6, t -= 6;
      bit |= ((1 << t) - 1) - ((1 << s) - 1);
    }

    rep(S, 1 << 16) {
      maximize(dp[(i + 1) & 1][S], dp[i & 1][S]);
      if ((S ^ bit) == (S + bit)) {
        int nS = S ^ bit;
        maximize(dp[(i + 1) & 1][nS], dp[i & 1][S] + L);
      }
    }
  }

  return *max_element(dp[N & 1], dp[N & 1] + (1 << 16));
}

int main() {
  for (int N; ~scanf("%d", &N) && N;) {
    printf("%lld\n", solve(N));
  }

  return 0;
}