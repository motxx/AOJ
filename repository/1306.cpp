#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;
ll const INF = 1LL << 50;

int main() {
  int N;
  while (cin >> N && N) {
    N += 2;
    int p[N], t[N];
    p[0] = t[0] = 0;
    REP(i, 1, N - 1) { cin >> p[i] >> t[i]; }
    p[N - 1] = 0, t[N - 1] = 1 << 29;

    ll dp[4], next[4];
    rep(_, 4) dp[_] = INF;
    dp[0] = 0;
    bool good = 1;
    rep(i, N - 1) {
      rep(_, 4) next[_] = INF;
      int p1 = p[i], p2 = p[i + 1];
      int t1 = t[i], t2 = t[i + 1];
      rep(j, 4) {
        if (dp[j] == INF) continue;
        if (j < 3 && abs(p2 - p1) * (j + 1) <= t2 - t1) {
          next[j + 1] = min(next[j + 1], dp[j] + abs(p2 - p1));
        }
        if (p1 * (j + 1) + p2 <= t2 - t1) {
          next[1] = min(next[1], dp[j] + p1 + p2);
        }
      }
      bool ng = 1;
      rep(j, 4) {
        if (next[j] < INF) ng = 0;
      }
      if (ng) {
        cout << "NG " << i + 1 << endl;
        good = 0;
        break;
      }
      rep(j, 4) { dp[j] = next[j]; }
    }
    if (good) {
      ll k = INF;
      rep(i, 3) { k = min(k, dp[i]); }
      cout << "OK " << k << endl;
    }
  }
  return 0;
}