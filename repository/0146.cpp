#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  double const INF = 1e14;

  int N;
  cin >> N;
  double dist[N];
  int ID[20], weights[N];
  rep(i, N) {
    int id;
    cin >> id;
    ID[i] = id;
    cin >> dist[i] >> weights[i];
  }

  double Weight[1 << N];
  rep(i, 1 << N) {
    Weight[i] = 0;
    rep(j, N) {
      if (i >> j & 1) Weight[i] += weights[j] * 20;
    }
  }

  double dp[1 << N][N];
  fill(dp[0], dp[1 << N], INF);
  pair<int, int> prev[1 << N][N];
  rep(i, N) { dp[1 << i][i] = 0.; }

  rep(S, (1 << N) - 1) {
    rep(u, N) {
      if (!(S & (1 << u))) continue;
      if (dp[S][u] == INF) continue;
      rep(v, N) {
        if (S & (1 << v)) continue;
        int nS = S | (1 << v);
        double cand =
            dp[S][u] + abs(dist[u] - dist[v]) * (70. + Weight[S]) / 2000.;
        if (dp[nS][v] > cand) {
          dp[nS][v] = cand;
          prev[nS][v].first = S;
          prev[nS][v].second = u;
        }
      }
    }
  }

  int last = -1;
  double mn = INF;
  rep(i, N) {
    if (mn > dp[(1 << N) - 1][i]) {
      mn = dp[(1 << N) - 1][i];
      last = i;
    }
  }

  vector<int> ans;
  int S = (1 << N) - 1;
  rep(i, N) {
    ans.push_back(ID[last]);
    int nS = prev[S][last].first, nlast = prev[S][last].second;
    S = nS, last = nlast;
  }
  reverse(ans.begin(), ans.end());
  rep(i, N) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << endl;

  return 0;
}