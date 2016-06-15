#include <algorithm>
#include <iostream>

using namespace std;

int const MAX_R = 1010;
int const MAX_N = 210;
int const INF = 1 << 29;

long long dl[MAX_N][MAX_N];
long long ds[MAX_N][MAX_N];
long long dp[MAX_R][MAX_N];
int z[MAX_R];
int N, M, R;

int main() {
  while (cin >> N >> M && (N | M)) {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        dl[i][j] = dl[j][i] = INF;
        ds[i][j] = ds[j][i] = INF;
      }
      dl[i][i] = dl[i][i] = ds[i][i] = ds[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
      int x, y, t;
      char sl;
      cin >> x >> y >> t >> sl;
      x--, y--;
      if (sl == 'L') {
        dl[x][y] = dl[y][x] = t;
      } else {
        ds[x][y] = ds[y][x] = t;
      }
    }

    for (int k = 0; k < N; k++)
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
          dl[i][j] = min(dl[i][j], dl[i][k] + dl[k][j]);
          ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
        }

    cin >> R;
    for (int i = 0; i < R; i++) {
      cin >> z[i];
      z[i]--;
    }

    fill(dp[0], dp[0] + MAX_R * MAX_N, INF);
    dp[0][z[0]] = 0;

    for (int i = 1; i < R; i++) {
      for (int s = 0; s < N; s++) {
        for (int t = 0; t < N; t++) {
          dp[i][t] = min(dp[i][t], dp[i - 1][s] + dl[z[i - 1]][s] + ds[s][t] +
                                       dl[t][z[i]]);
        }
        dp[i][s] = min(dp[i][s], dp[i - 1][s] + dl[z[i - 1]][z[i]]);
      }
    }

    cout << *min_element(dp[R - 1], dp[R]) << endl;
  }

  return 0;
}