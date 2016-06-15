#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int H, W, C;
VVI p;

int const dx[] = {-1, 0, 1, 0};
int const dy[] = {0, -1, 0, 1};

int ans;

inline bool inF(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

void dfs2(int x, int y, int now, int next) {
  p[y][x] = next;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (inF(nx, ny) && p[ny][nx] == now) {
      dfs2(nx, ny, now, next);
    }
  }
}

vector<vector<bool> > vis;
int cnt_panel(int x, int y) {
  int res = 0;
  vis[y][x] = true;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (inF(nx, ny) && !vis[ny][nx] && p[ny][nx] == C) {
      res += cnt_panel(nx, ny);
    }
  }
  return res + 1;
}

void change(int cnt) {
  if (cnt == 5) {
    vis.clear();
    vis.resize(H);
    for (int i = 0; i < H; i++) vis[i].resize(W);
    ans = max(ans, cnt_panel(0, 0));
    return;
  }

  if (cnt == 4) {
    if (p[0][0] == C) return;
    dfs2(0, 0, p[0][0], C);
    change(cnt + 1);
  } else {
    VVI tmp(p);
    for (int next = 1; next <= 6; next++) {
      if (p[0][0] == next) continue;
      dfs2(0, 0, p[0][0], next);
      change(cnt + 1);
      p = tmp;
    }
  }
}

int main() {
  for (; cin >> H >> W >> C && (H | W | C);) {
    p.clear();
    p.resize(H);
    for (int i = 0; i < H; i++) p[i].resize(W);
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) cin >> p[i][j];

    ans = 0;
    change(0);
    cout << ans << endl;
  }

  return 0;
}