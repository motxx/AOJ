#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int const INF = 1 << 29;

int N, M, L, S, T;
int eat[20];
map<int, int> loc;
int lcnt;
map<int, int> locrev;

typedef long long ll;

ll dp[1 << 17][17];

void init() {
  loc.clear();
  locrev.clear();
}

int main() {
  while (cin >> N >> M >> L >> S >> T && (N | M | L | S | T)) {
    S--;

    init();

    int rawg[N][N];
    fill(rawg[0], rawg[0] + N * N, INF);

    rep(i, M) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      rawg[a][b] = rawg[b][a] = c;
    }

    lcnt = 0;
    rep(i, L) {
      int eattime, rawlocation;
      cin >> rawlocation >> eattime;
      rawlocation--;
      loc[rawlocation] = lcnt;
      eat[lcnt] = eattime;
      locrev[lcnt] = rawlocation;
      lcnt++;
    }

    if (loc.find(S) == loc.end()) {
      eat[lcnt] = 0;
      loc[S] = lcnt;
      locrev[lcnt] = S;
      lcnt++;
      // cout << "S: " << S << " loc[S]: " << loc[S] << endl;
    }

    rep(i, N) rawg[i][i] = 0;
    rep(k, N) rep(i, N) rep(j, N) {
      if (rawg[i][k] != INF && rawg[k][j] != INF) {
        rawg[i][j] = min(rawg[i][j], rawg[i][k] + rawg[k][j]);
      }
    }

    ll graph[lcnt][lcnt];
    fill(graph[0], graph[0] + lcnt * lcnt, INF);

    rep(i, N) {
      if (loc.find(i) == loc.end()) {
        continue;
      }
      REP(j, i + 1, N) {
        if (loc.find(j) == loc.end()) {
          continue;
        }
        graph[loc[i]][loc[j]] = graph[loc[j]][loc[i]] = rawg[i][j];
      }
    }

    fill(dp[0], dp[0] + (1 << 17) * 17, INF);
    dp[1 << loc[S]][loc[S]] = 0;

    rep(state, 1 << lcnt) {
      rep(i, lcnt) {
        if (!(state >> i & 1)) continue;
        rep(j, lcnt) {
          if (state >> j & 1) continue;
          int next = state | (1 << j);
          if (graph[i][j] < INF) {
            int cost = graph[i][j] + eat[j];
            if (dp[next][j] > dp[state][i] + cost) {
              dp[next][j] = dp[state][i] + cost;
            }
          }
        }
      }
    }

    // cerr << "Case" << endl;

    int ans = 0;
    rep(state, 1 << lcnt) {
      rep(i, lcnt) {
        if (dp[state][i] >= INF) continue;

        int sumcost = dp[state][i] + rawg[locrev[i]][S];
        if (sumcost <= T) {
          //  cerr << "PASS " << sumcost << " " << T << endl;;
          ans = max(ans, __builtin_popcount(state));
        }
      }
    }

    cout << ans - 1 << endl;
  }

  return 0;
}