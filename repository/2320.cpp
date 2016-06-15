#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define minus(a) memset(a, -1, sizeof a)
typedef long long ll;
template <class T>
constexpr bool in_range(T y, T x, T H, T W) {
  return 0 <= y && y < H && 0 <= x && x < W;
}

int main() {
  int dy[] = {0, -1, 0, 1};
  int dx[] = {-1, 0, 1, 0};
  string WNES = "WNES";
  int H, W;
  ll L;
  for (; cin >> H >> W >> L && (H | W | L);) {
    string G[100];
    rep(i, H) cin >> G[i];
    int y = 0, x = 0, k = 0, c = 0;
    rep(i, H) rep(j, W) if (isalpha(G[i][j])) y = i, x = j,
                                              k = WNES.find(G[i][j]);
    int T[100][100][4];
    minus(T);
    vector<int> ys, xs, ds;

    while (1) {
      int ny = y + dy[k], nx = x + dx[k];
      while (!in_range(ny, nx, H, W) || G[ny][nx] == '#')
        (k += 1) %= 4, ny = y + dy[k], nx = x + dx[k];
      y = ny, x = nx;
      c++;
      if (~T[y][x][k]) {
        int len = c - T[y][x][k];
        (L -= T[y][x][k]) %= len;
        L += T[y][x][k] - 1;
        cout << ys[L] + 1 << " " << xs[L] + 1 << " " << WNES[ds[L]] << endl;
        break;
      }
      if (c == L) {
        cout << y + 1 << " " << x + 1 << " " << WNES[k] << endl;
        break;
      }
      ys.push_back(y), xs.push_back(x), ds.push_back(k);
      T[y][x][k] = c;
    }
  }

  return 0;
}