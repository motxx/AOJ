#include <algorithm>
#include <iostream>
using namespace std;

int cnt, MX;
int M[92][92];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int y, int x) {
  M[y][x] = 0;
  cnt++;

  int ny, nx, flag = 0;

  for (int i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];

    if (M[ny][nx])
      dfs(ny, nx);
    else
      flag++;
  }
  if (flag == 4) MX = max(MX, cnt);
  M[y][x] = 1;
  cnt--;
}

int main() {
  int m, n;

  while (1) {
    cin >> m >> n;
    if (m == 0 && n == 0) break;

    for (int i = 0; i <= 91; i++) {
      for (int j = 0; j <= 91; j++) {
        M[i][j] = 0;
      }
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> M[i][j];
      }
    }

    // int mx = 0;
    MX = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (M[i][j]) {
          cnt = 0;
          dfs(i, j);
        }
      }
    }

    cout << MX << endl;
  }
  return 0;
}