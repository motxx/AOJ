#include <algorithm>
#include <iostream>

using namespace std;

int const INF = 1 << 29;

int main() {
  int N, M, S, g1, g2;

  while (cin >> N >> M >> S >> g1 >> g2 && N) {
    int cost[100][100];
    fill(cost[0], cost[0] + 10000, INF);
    for (int i = 0; i < N; i++) cost[i][i] = 0;
    S--, g1--, g2--;
    for (int i = 0; i < M; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      cost[a][b] = c;
    }

    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    int ans = INF;
    for (int k = 0; k < N; k++) {
      ans = min(ans, cost[S][k] + cost[k][g1] + cost[k][g2]);
    }

    cout << ans << endl;
  }

  return 0;
}