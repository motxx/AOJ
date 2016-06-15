#include <algorithm>
#include <iostream>
using namespace std;
int const INF = 1 << 18;
int main() {
  int N, M;
  cin >> N >> M;
  int G[420][420];
  fill(G[0], G[0] + 410 * 410, -INF);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    cin >> G[a][b];
  }
  for (int i = 0; i < N; i++) G[i][i] = 0;
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) G[i][j] = max(G[i][j], G[i][k] + G[k][j]);
  cout << G[0][N - 1] << endl;
  return 0;
}