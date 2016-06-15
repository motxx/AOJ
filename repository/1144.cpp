#include <algorithm>
#include <iostream>

using namespace std;

int W, H;
int M[20][20];
int ans;

bool in(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(const int& sx, const int& sy, int k) {
  if (k >= 11) return;

  for (int i = 0; i < 4; i++) {
    int x = sx, y = sy;
    int nx = x + dx[i], ny = y + dy[i];

    if (in(nx, ny) && M[ny][nx] == 1) continue;

    while (in(nx, ny)) {
      if (M[ny][nx] == 3) {
        ans = min(ans, k);
        break;
      }
      if (M[ny][nx] == 1) {
        M[ny][nx] = 0;
        dfs(x, y, k + 1);
        M[ny][nx] = 1;
        break;
      }
      x = nx, y = ny;
      nx = x + dx[i], ny = y + dy[i];
    }
  }
}

int main() {
  int stx, sty;

  while (cin >> W >> H && (W | H)) {
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cin >> M[i][j];
        if (M[i][j] == 2) stx = j, sty = i;
      }
    }

    ans = 11;
    dfs(stx, sty, 1);

    cout << (ans <= 10 ? ans : -1) << endl;
  }

  return 0;
}