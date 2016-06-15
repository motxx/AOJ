#include <cstring>
#include <iostream>

using namespace std;

int used[20][20];
char M[20][20];
int W, H;

bool in(int sx, int sy) { return 0 <= sx && sx < W && 0 <= sy && sy < H; }

int dfs(int x, int y) {
  int res = 1;
  used[y][x] = 1;

  const int dx[] = {-1, 1, 0, 0};
  const int dy[] = {0, 0, -1, 1};
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (in(nx, ny) && M[ny][nx] == '.' && !used[ny][nx]) res += dfs(nx, ny);
  }
  return res;
}

int main() {
  int stx, sty;
  while (cin >> W >> H, (W | H)) {
    memset(used, 0, sizeof(used));
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) {
        cin >> M[i][j];
        if (M[i][j] == '@') {
          stx = j, sty = i;
          M[i][j] = '.';
        }
      }
    cout << dfs(stx, sty) << endl;
  }

  return 0;
}