#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int H, W;
char grid[110][110];

int const dx[4] = {-1, 1, 0, 0};
int const dy[4] = {0, 0, -1, 1};

int memo[101][101];

inline bool IN(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

int const INF = 1 << 29;

int main() {
  while (cin >> W >> H && W) {
    int sx, sy;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == '&') {
          sx = j, sy = i;
          grid[i][j] = '.';
        }
      }
    }

    int ans = 1 << 29;

    memset(memo, -1, sizeof(memo));
    typedef pair<int, int> Pii;
    typedef pair<int, Pii> Piii;

    priority_queue<Piii> Q;
    Q.push(Piii(0, Pii(sx, sy)));
    while (!Q.empty()) {
      Piii piii = Q.top();
      Q.pop();
      int const x = piii.second.first;
      int const y = piii.second.second;
      int const cost = -piii.first;

      if (x == 0 || y == 0 || x == W - 1 || y == H - 1) {
        cout << cost << endl;
        break;
      }

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (IN(nx, ny)) {
          int ncost = cost + (grid[y][x] == '.' && grid[ny][nx] == '#');
          if (memo[ny][nx] == -1 || memo[ny][nx] > ncost) {
            memo[ny][nx] = ncost;
            Q.push(Piii(-ncost, Pii(nx, ny)));
          }
        }
      }
    }
  }

  return 0;
}