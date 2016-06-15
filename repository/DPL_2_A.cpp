#include <iostream>

using namespace std;

#define MAX_V (15)
#define INF (1 << 29)

int V;
int cost[MAX_V][MAX_V];
int dp[1 << MAX_V][MAX_V];

int main() {
  cin >> V;

  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++) cost[i][j] = INF;

  int m;

  cin >> m;
  for (int i = 0; i < m; i++) {
    int s, t, c;
    cin >> s >> t >> c;
    cost[s][t] = c;
  }

  int SMAX = 1 << V;

  for (int i = 0; i < SMAX; i++)
    for (int j = 0; j < V; j++) dp[i][j] = INF;

  dp[SMAX - 1][0] = 0;
  for (int S = SMAX - 2; S >= 0; S--)
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        if (!(S >> j & 1))
          dp[S][i] = min(dp[S][i], dp[S | (1 << j)][j] + cost[i][j]);

  cout << (dp[0][0] == INF ? -1 : dp[0][0]) << endl;

  return 0;
}