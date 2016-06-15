#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 1 << 20;

int GM[100][100];
int GT[100][100];

int main() {
  int n, m, a, b, c, t;
  int K, p, q, r;

  while (cin >> n >> m, n + m) {
    fill(GM[0], GM[100], INF);
    fill(GT[0], GT[100], INF);
    for (int i = 0; i < m; i++) {
      GM[i][i] = 0;
      GT[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c >> t;
      a--, b--;
      GM[a][b] = c, GM[b][a] = c;
      GT[a][b] = t, GT[b][a] = t;
    }

    for (int k = 0; k < m; k++)
      for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
          GM[i][j] = min(GM[i][j], GM[i][k] + GM[k][j]);
          GT[i][j] = min(GT[i][j], GT[i][k] + GT[k][j]);
        }

    cin >> K;
    for (int i = 0; i < K; i++) {
      cin >> p >> q >> r;
      p--, q--;
      if (r) {
        cout << GT[p][q] << endl;
      } else {
        cout << GM[p][q] << endl;
      }
    }
  }

  return 0;
}