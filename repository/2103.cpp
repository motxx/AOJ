#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int H, W;
vector<string> G;
int N;
string S;
int sy, sx, sd;

string const DIRS = "LURD";
string const CDIRS = "<^>v";

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool in_range(int y, int x) {
  if (!(0 <= y && y < H && 0 <= x && x < W)) return false;
  return true;
}

bool in_move_range(int y, int x) {
  if (!(0 <= y && y < H && 0 <= x && x < W)) return false;
  if (G[y][x] == '*') return false;
  if (G[y][x] == '-') return false;
  if (G[y][x] == '#') return false;
  return true;
}

void solve() {
  int y = sy, x = sx, dir = sd;

  rep(idx, N) {
    if (DIRS.find(S[idx]) != string::npos) {
      dir = (int)DIRS.find(S[idx]);
      int ny = y + dy[dir], nx = x + dx[dir];
      if (!in_move_range(ny, nx)) continue;
      y = ny, x = nx;
    } else {
      int by = y, bx = x;
      while (1) {
        by += dy[dir], bx += dx[dir];
        if (!in_range(by, bx)) break;
        if (G[by][bx] == '*') {
          G[by][bx] = '.';
          break;
        }
        if (G[by][bx] == '#') {
          break;
        }
      }
    }
  }

  rep(i, H) rep(j, W + 1) {
    if (j == W)
      cout << endl;
    else {
      if (y == i && x == j)
        cout << CDIRS[dir];
      else
        cout << G[i][j];
    }
  }
}

int main() {
  int T;
  cin >> T;
  rep(_, T) {
    if (_) cout << endl;

    cin >> H >> W;
    G.clear();
    G.resize(H);
    rep(i, H) { cin >> G[i]; }

    rep(i, H) rep(j, W) {
      if (CDIRS.find(G[i][j]) != string::npos) {
        sd = CDIRS.find(G[i][j]);
        sy = i, sx = j;
        G[sy][sx] = '.';
      }
    }

    cin >> N;

    cin >> S;

    solve();
  }

  return 0;
}