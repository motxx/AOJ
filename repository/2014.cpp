#include <algorithm>
#include <iostream>

using namespace std;

int W, H;
int col, cnt;
char M[50][50];
bool used[50][50];

#define BLACK (1)
#define WHITE (2)

int in(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

void dfs(int x, int y) {
  // 周りが一つの色かフィールド外だけで構成されると領域にカウント
  if (M[y][x] != '.') return;
  used[y][x] = true;
  cnt++;

  const int dx[] = {-1, 1, 0, 0};
  const int dy[] = {0, 0, -1, 1};

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (in(nx, ny) && !used[ny][nx]) {
      if (M[ny][nx] == 'B') col |= BLACK;
      if (M[ny][nx] == 'W') col |= WHITE;
      if (M[ny][nx] == '.') dfs(nx, ny);
    }
  }
}

int main() {
  while (cin >> W >> H && W) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) cin >> M[i][j];

    fill(used[0], used[0] + 2500, false);

    int res[4] = {};
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++)
        if (!used[i][j]) {
          col = cnt = 0;
          dfs(j, i);
          res[col] += cnt;
        }

    cout << res[BLACK] << " " << res[WHITE] << endl;
  }

  return 0;
}