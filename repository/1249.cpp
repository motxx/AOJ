#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int N, M, P;

int F[10][10][10];
int Fsize[10][10];

int ansf;

#define ck(x) (0 <= (x) && (x) < N)
#define ck3(x, y, z) (ck(x) && ck(y) && ck(z))

void dfs(int x, int y, int z, int dx, int dy, int dz, int col, int cnt) {
  if (col != F[z][y][x]) {
    return;
  }
  if (cnt == M - 1) {
    ansf += col;
    return;
  }
  int nx = x + dx, ny = y + dy, nz = z + dz;
  if (!ck3(nx, ny, nz)) return;
  dfs(nx, ny, nz, dx, dy, dz, col, cnt + 1);
}

int main() {
  while (cin >> N >> M >> P && (N | M | P)) {
    rep(i, 10) rep(j, 10) {
      Fsize[i][j] = 0;
      rep(k, 10) F[i][j][k] = 0;
    }

    ansf = 0;
    int xs[P], ys[P];
    rep(i, P) {
      cin >> xs[i] >> ys[i];
      xs[i]--, ys[i]--;
    }
    rep(turn, P) {
      int x = xs[turn], y = ys[turn];
      F[Fsize[y][x]++][y][x] = turn % 2 ? 1 : -1;

      rep(i, N) rep(j, N) rep(k, N) REP(dx, -1, 2) REP(dy, -1, 2)
          REP(dz, -1, 2) {
        if (dx == 0 && dy == 0 && dz == 0) continue;
        rep(ci, 2) { dfs(i, j, k, dx, dy, dz, ci % 2 ? 1 : -1, 0); }
        if (ansf) {
          if (ansf == -1) {
            cout << "Black " << turn + 1 << endl;
          }
          if (ansf == 1) {
            cout << "White " << turn + 1 << endl;
          }
          goto exit;
        }
      }
    }

  exit:;
    if (!ansf) {
      cout << "Draw\n";
    }
  }

  return 0;
}