#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Pii;
typedef pair<int, pair<Pii, Pii> > Tpl;
#define fi first
#define se second
int W, H;
int const INF = 1 << 29;
inline bool inF(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

int main() {
  int const dx[] = {-1, 0, 1, 0};
  int const dy[] = {0, -1, 0, 1};
  while (cin >> W >> H && (W | H)) {
    int tx, ty, kx, ky;
    cin >> tx >> ty >> kx >> ky;
    tx--;
    ty--;
    kx--;
    ky--;
    int grid[51][51];
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) cin >> grid[i][j];

    static int vis[51][51][51][51];
    fill(vis[0][0][0], vis[51][0][0], INF);

    queue<Tpl> Q;
    Q.push(Tpl(make_pair(0, make_pair(Pii(tx, ty), Pii(kx, ky)))));
    vis[ty][tx][ky][kx] = 0;
    int ans = -1;
    while (!Q.empty()) {
      Tpl t = Q.front();
      Q.pop();
      const int tx = t.se.fi.fi, ty = t.se.fi.se, kx = t.se.se.fi,
                ky = t.se.se.se;
      const int cost = t.fi;
      for (int i = 0; i < 4; i++) {
        int ntx = tx + dx[i], nty = ty + dy[i];
        int nkx = kx - dx[i], nky = ky - dy[i];
        if (tx == kx && ty == ky) {
          ans = cost;
          goto EXIT;
        }
        if (!inF(ntx, nty) && !inF(nkx, nky)) continue;
        if (!inF(ntx, nty)) ntx = tx, nty = ty;
        if (!inF(nkx, nky)) nkx = kx, nky = ky;
        if (grid[nty][ntx] && grid[nky][nkx]) continue;
        if (grid[nty][ntx]) ntx = tx, nty = ty;
        if (grid[nky][nkx]) nkx = kx, nky = ky;
        if (vis[nty][ntx][nky][nkx] > cost + 1) {
          vis[nty][ntx][nky][nkx] = cost + 1;
          Q.push(Tpl(cost + 1, make_pair(Pii(ntx, nty), Pii(nkx, nky))));
        }
      }
    }

  EXIT:;
    if (ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }

  return 0;
}