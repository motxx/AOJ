#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int H, W;
char grid[22][22];
typedef pair<int, int> Pii;

int cost[22][22][22][22];
int dist[12][12];
int dp[1 << 12][12];
map<Pii, int> dmap;
#define MP make_pair

#define INF ((int)1e8)

int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, -1, 0, 1};

inline bool inF(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

bool bfs(int SX, int SY) {
#define COST(x, y) cost[SY][SX][y][x]

  fill(&COST(0, 0), &COST(0, 0) + 22 * 22, INF);
  queue<Pii> Q;
  Q.push(Pii(SX, SY));
  COST(SX, SY) = 0;
  while (!Q.empty()) {
    Pii pii = Q.front();
    Q.pop();
    int x = pii.first, y = pii.second;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (!inF(nx, ny)) continue;
      if (COST(nx, ny) != INF) continue;
      if (grid[ny][nx] == 'x') continue;
      COST(nx, ny) = COST(x, y) + 1;
      Q.push(Pii(nx, ny));
    }
  }

  bool ok = true;
  rep(i, H) rep(j, W) if (grid[i][j] == '*' && COST(j, i) == INF) ok = false;

  return ok;
}

int main() {
  while (cin >> W >> H && (W | H)) {
    dmap.clear();

    int dsx, dsy;
    int dcnt = 1;
    rep(i, H) rep(j, W) {
      cin >> grid[i][j];
      if (grid[i][j] == 'o') {
        dsx = j, dsy = i;
        dmap[Pii(j, i)] = 0;
      }
      if (grid[i][j] == '*') {
        dmap[Pii(j, i)] = dcnt++;
      }
    }

    bool NA = false;
    rep(i, H) rep(j, W) {
      if (grid[i][j] == '*' || grid[i][j] == 'o') {
        if (!bfs(j, i)) {
          cout << -1 << endl;
          NA = true;
          i = j = INF;
        }
      }
    }
    if (NA) continue;

    rep(i, H) rep(j, W) rep(k, H) rep(l, W) {
      if (i == k && j == l) continue;
      if ((grid[i][j] == '*' && grid[k][l] == '*') ||
          (grid[i][j] == 'o' && grid[k][l] == '*')) {
        dist[dmap[Pii(j, i)]][dmap[Pii(l, k)]] = cost[i][j][k][l];
      }
    }

    int V = dcnt;

    for (int i = 0; i < (1 << V); i++) fill(dp[i], dp[i] + 12, INF);
    dp[(1 << V) - 1][0] = 0;

    for (int st = (1 << V) - 2; st >= 0; st--) {
      for (int v = 0; v < V; v++) {
        for (int u = 0; u < V; u++) {
          if (!((st >> u) & 1)) {
            dp[st][v] = min(dp[st][v], dp[st | (1 << u)][u] + dist[v][u]);
          }
        }
      }
    }

    cout << dp[0][0] << endl;
  }

  return 0;
}