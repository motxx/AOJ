#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

ll N, M, K;

ll dfs(ll S, ll cnt) {
  if (cnt == N) {
    if (S - K <= 0) {
      return 1;
    }
    return S - K;
  }

  ll ret = 0;
  REP(i, 1, M + 1) { ret += dfs(S + i, cnt + 1); }
  return ret;
}

int main() {
  while (cin >> N >> M >> K && (N | M | K)) {
    printf("%.10f\n", dfs(0, 0) / pow(M, N));
  }

  return 0;
}