#include <bits/stdc++.h>

using namespace std;

#define CK(n, a, b) (a <= n && n < b)

int main() {
  int N;

  while (cin >> N && N) {
    vector<string> G(N);
    for (int i = 0; i < N; i++) {
      cin >> G[i];
    }

    int grid[N][N];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        grid[i][j] = G[i][j] - '0';
      }
    }

    int ans = 0;

    // right
    for (int i = 0; i < N; i++) {
      int cnt = 0;
      for (int j = 0; j < N; j++) {
        if (!grid[i][j])
          cnt = 0;
        else
          cnt++;
        ans = max(ans, cnt);
      }
    }

    // down
    for (int j = 0; j < N; j++) {
      int cnt = 0;
      for (int i = 0; i < N; i++) {
        if (!grid[i][j])
          cnt = 0;
        else
          cnt++;
        ans = max(ans, cnt);
      }
    }

    // right down
    for (int i = 0; i < N; i++) {
      int sx = i, sy = 0;
      int cnt = 0;
      for (int k = 0; k < N; k++) {
        if (!CK(sy + k, 0, N) || !CK(sx + k, 0, N)) break;
        if (!grid[sy + k][sx + k])
          cnt = 0;
        else
          cnt++;
        ans = max(ans, cnt);
      }
    }
    for (int i = 0; i < N; i++) {
      int sx = 0, sy = i;
      int cnt = 0;
      for (int k = 0; k < N; k++) {
        if (!CK(sy + k, 0, N) || !CK(sx + k, 0, N)) break;
        if (!grid[sy + k][sx + k])
          cnt = 0;
        else
          cnt++;
        ans = max(ans, cnt);
      }
    }

    // left down
    for (int i = 0; i < N; i++) {
      int sx = N - 1, sy = i;
      int cnt = 0;
      for (int k = 0; k < N; k++) {
        if (!CK(sy + k, 0, N) || !CK(sx - k, 0, N)) break;
        if (!grid[sy + k][sx - k])
          cnt = 0;
        else
          cnt++;
        ans = max(ans, cnt);
      }
    }
    for (int i = 0; i < N; i++) {
      int sx = i, sy = 0;
      int cnt = 0;
      for (int k = 0; k < N; k++) {
        if (!CK(sy + k, 0, N) || !CK(sx - k, 0, N)) break;
        if (!grid[sy + k][sx - k])
          cnt = 0;
        else
          cnt++;
        ans = max(ans, cnt);
      }
    }

    cout << ans << endl;
  }

  return 0;
}