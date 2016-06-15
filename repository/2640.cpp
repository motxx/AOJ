#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define zero(a) memset(a, 0, sizeof a)

template <class T>
constexpr bool in_range(T y, T x, T H, T W) {
  return 0 <= y && y < H && 0 <= x && x < W;
}

vector<vector<string>> D[4] = {{
                                   {"x#x", "<<x", "xxx"},
                                   {"x#x", "#<x", "xvx"},
                                   {"x#x", "#<>", "x#x"},
                                   {"x^#", "x<x", "xxx"},
                               },
                               {
                                   {"x^x", "x^#", "xxx"},
                                   {"x#x", "<^#", "xxx"},
                                   {"x#x", "#^#", "xvx"},
                                   {"xxx", "x^>", "xx#"},
                               },
                               {
                                   {"xxx", "x>>", "x#x"},
                                   {"x^x", "x>#", "x#x"},
                                   {"x#x", "<>#", "x#x"},
                                   {"xxx", "x>x", "#vx"},
                               },
                               {
                                   {"xxx", "#vx", "xvx"},
                                   {"xxx", "#v>", "x#x"},
                                   {"x^x", "#v#", "x#x"},
                                   {"#xx", "<vx", "xxx"},
                               }};

const string dirs = "<^>v";
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

char G[55][55];
int H, W;

tuple<int, int, int> walk(int y, int x, int d) {
  tuple<int, int, int> next;
  rep(i, D[d].size()) {
    auto& T = D[d][i];
    assert(dirs.find(T[1][1]) == d);

    bool ok = 1;
    int ry = -1, rx = -1, rd = -1;
    REP(i, -1, 2) REP(j, -1, 2) {
      if (i == 0 && j == 0) continue;
      const int ny = y + i, nx = x + j;
      if (T[i + 1][j + 1] == 'x') {
        continue;
      } else if (T[i + 1][j + 1] == '#') {
        ok &= !in_range(ny, nx, H, W) || G[ny][nx] == '#';
      } else {
        ok &= in_range(ny, nx, H, W) && G[ny][nx] != '#';
        if (ok) {
          assert(dirs.find(T[i + 1][j + 1]) != string::npos);
          ry = ny, rx = nx, rd = dirs.find(T[i + 1][j + 1]);
        }
      }
    }
    if (ok) {
      next = make_tuple(ry, rx, rd);
    }
  }
  return next;
}

int main() {
  cin >> H >> W;
  rep(i, H) { cin >> G[i]; }

  int y, x, d;

  rep(i, H) rep(j, W) {
    if (dirs.find(G[i][j]) != string::npos) {
      y = i, x = j, d = dirs.find(G[i][j]);
    }
  }

  bool vis[55][55][4];
  zero(vis);
  vis[y][x][d] = 1;

  while (1) {
    auto next = walk(y, x, d);
    tie(y, x, d) = next;
    if (vis[y][x][d]) break;
    vis[y][x][d] = 1;
    if (G[y][x] == 'G') {
      int ans = 0;
      rep(i, 55) rep(j, 55) ans +=
          vis[i][j][0] || vis[i][j][1] || vis[i][j][2] || vis[i][j][3];
      cout << ans << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}