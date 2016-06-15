#include <iostream>
using namespace std;
int H, W, cnt, t[102][102], vis[102][102];
int dx[2][6] = {{-1, 0, 0, -1, -1, 1}, {1, 1, 1, 0, -1, 0}};

int dy[2][6] = {{0, -1, 1, -1, 1, 0}, {-1, 0, 1, 1, 0, -1}};
void dfs(int y, int x) {
  int nx, ny;

  t[y][x] = -1;
  for (int i = 0; i < 6; i++) {
    nx = x + dx[y % 2][i];
    ny = y + dy[y % 2][i];
    if (nx < 0 || W + 1 < nx || ny < 0 || ny > H + 1) continue;
    if (t[ny][nx] == 1) {
      cnt++;
    }
    if (t[ny][nx] == 0) {
      dfs(ny, nx);
    }
  }
}
int main() {
  cin >> W >> H;
  for (int i = 0; i < 102; i++) {
    for (int j = 0; j < 102; j++) {
      t[i][j] = 0;
    }
  }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> t[i][j];
    }
  }
  cnt = 0;
  dfs(0, 0);
  cout << cnt << endl;
  return 0;
}