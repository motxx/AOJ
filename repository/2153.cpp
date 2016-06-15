#include <bits/stdc++.h>

using namespace std;

int const dxL[] = {-1, 0, 1, 0};
int const dxR[] = {1, 0, -1, 0};
int const dy[] = {0, -1, 0, 1};
typedef pair<int, int> Pii;
#define X first
#define Y second
int const INF = 1 << 28;
int W, H;
char grL[51][51], grR[51][51];
bool used[2500][2500];
inline bool isValid(int x, int y) {
  if (0 <= x && x < W && 0 <= y && y < H) return true;
  return false;
}

inline bool inF(int x, int y, int isL) {
  if (isL) return grL[y][x] != '#';
  return grR[y][x] != '#';
}
inline int toNode(int x, int y) { return y * W + x; }
inline void toPos(int node, int &x, int &y) { x = node % W, y = node / W; }
int main() {
  while (cin >> W >> H && (W | H)) {
    int sxL, syL, sxR, syR;
    int gxL, gyL, gxR, gyR;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < 2 * W; j++) {
        if (j < W) {
          cin >> grL[i][j];
          if (grL[i][j] == 'L') {
            sxL = j, syL = i;
          }
          if (grL[i][j] == '%') {
            gxL = j, gyL = i;
          }
        } else {
          cin >> grR[i][j - W];
          if (grR[i][j - W] == 'R') {
            sxR = j - W, syR = i;
          }
          if (grR[i][j - W] == '%') {
            gxR = j - W, gyR = i;
          }
        }
      }
    }

    queue<Pii> que;
    que.push(make_pair(toNode(sxL, syL), toNode(sxR, syR)));
    bool ok = false;
    memset(used, false, sizeof used);
    while (!que.empty()) {
      const int nowL = que.front().first;
      const int nowR = que.front().second;
      que.pop();
      int lx, ly;
      toPos(nowL, lx, ly);
      int rx, ry;
      toPos(nowR, rx, ry);

      if (lx == gxL && ly == gyL && rx == gxR && ry == gyR) {
        ok = true;
        break;
      }

      if (lx == gxL && ly == gyL) continue;
      if (rx == gxR && ry == gyR) continue;

      for (int i = 0; i < 4; i++) {
        int nxL = lx + dxL[i], nyL = ly + dy[i];
        int nxR = rx + dxR[i], nyR = ry + dy[i];

        if (!isValid(nxL, nyL) || !inF(nxL, nyL, 1)) {
          nxL = lx, nyL = ly;
        }
        if (!isValid(nxR, nyR) || !inF(nxR, nyR, 0)) {
          nxR = rx, nyR = ry;
        }
        if (used[toNode(nxL, nyL)][toNode(nxR, nyR)]) continue;
        que.push(make_pair(toNode(nxL, nyL), toNode(nxR, nyR)));
        used[toNode(nxL, nyL)][toNode(nxR, nyR)] = true;
      }
    }
    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}