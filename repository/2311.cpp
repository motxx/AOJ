#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

inline bool inrange(int x, int y) {
  return (0 <= x && x < 8) && (0 <= y && y < 8);
}

string F[8];
bool used[8][8];
int turn;

int dx, dy;
int dfs(int x, int y, char me, int cnt) {
  x += dx, y += dy;
  if (!inrange(x, y)) {
    return 0;
  }
  if (F[y][x] == '.') {
    return 0;
  }
  if (F[y][x] == me) {
    return cnt;
  }
  used[y][x] = 1;
  int r = dfs(x, y, me, cnt + 1);
  if (r == 0) {
    used[y][x] = 0;
  }
  return r;
}

#define DREP(i, a, b)                                        \
  for (int i = turn & 1 ? a : b; turn & 1 ? i >= b : i <= a; \
       turn & 1 ? i-- : i++)

int main() {
  rep(i, 8) cin >> F[i];
  int ucnt = 0;
  for (turn = 0; turn <= 64; turn++) {
    int pl;
    bool u[8][8] = {};
    int mx = 0;
    DREP(i, 7, 0) DREP(j, 7, 0) {
      if (F[i][j] == '.') {
        rep(a, 8) rep(b, 8) used[a][b] = 0;
        used[i][j] = 1;
        int r = 0;
        for (dy = -1; dy < 2; dy++)
          for (dx = -1; dx < 2; dx++) {
            if (dx == 0 && dy == 0) {
              continue;
            }
            r += dfs(j, i, "ox"[turn & 1], 0);
          }
        if (mx < r) {
          memcpy(u, used, sizeof u);
          mx = r;
          pl = turn & 1;
        }
      }
    }
    if (mx > 0) {
      rep(i, 8) rep(j, 8) if (u[i][j]) { F[i][j] = "ox"[pl]; }
      ucnt = 0;
    } else {
      if (ucnt) {
        break;
      }
      ucnt++;
    }
  }
  rep(i, 8) {
    rep(j, 8) { cout << F[i][j]; }
    puts("");
  }

  return 0;
}