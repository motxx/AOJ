#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int N;
bool bump(int x, int y) { return x < 0 || y < 0 || N <= x || N <= y; }

int main() {
  int Tc = 1;
  while (cin >> N && N) {
    int cnt = 1;
    int dx = 1, dy = -1;
    int x = 0, y = 0;
    int ans[N][N];

    for (;;) {
      ans[y][x] = cnt++;
      if (x == N - 1 && y == N - 1) break;
      x += dx, y += dy;
      if (x < N && y < N) {
        if (dx == -1 && bump(x, y)) {
          x++;
          dx = 1, dy = -1;
        } else if (dx == 1 && bump(x, y)) {
          y++;
          dx = -1, dy = 1;
        }
      } else {
        if (dx == -1 && bump(x, y)) {
          x += 2, y--;
          dx = 1, dy = -1;
        } else if (dx == 1 && bump(x, y)) {
          y += 2, x--;
          dx = -1, dy = 1;
        }
      }
    }
    printf("Case %d:\n", Tc++);
    rep(i, N) {
      rep(j, N) printf("%3d", ans[i][j]);
      puts("");
    }
  }

  return 0;
}