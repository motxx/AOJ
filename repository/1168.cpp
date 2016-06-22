#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
template <class T1, class T2> inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2> inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

int const inf = 1 << 29;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool in_range(int y, int x, int H, int W) {
  return 0 <= y && y < H && 0 <= x && x < W;
}

int H, W;
int K;
vector<string> G;
int color[66][11];

bool equals(double a, double b) { return abs(a - b) < 1e-10; }

struct Data {
  double y, x;
  int w;
  Data(double y, double x, int w) : y(y), x(x), w(w) {}
};

static auto InvalidData = Data(0, 0, -inf);

bool operator==(const Data &a, const Data &b) {
  return equals(a.y, b.y) && equals(b.x, b.x) && a.w == b.w;
}

void coloring(int y, int x, vector<vector<bool>> &vis) {
  color[y][x] = K;
  rep(k, 4) {
    int ny = y + dy[k], nx = x + dx[k];
    if (!in_range(ny, nx, H, W))
      continue;
    if (G[ny][nx] != G[y][x])
      continue;
    if (vis[ny][nx])
      continue;
    vis[ny][nx] = 1;
    coloring(ny, nx, vis);
  }
}

vector<int> getChildrenColors(int pcnum) {
  vector<int> ret;
  rep(i, H) rep(j, W) {
    if (color[i][j] == -1)
      continue;
    if (!in_range(i + 1, j, H, W))
      continue;
    if (color[i][j] != pcnum && color[i + 1][j] == pcnum)
      ret.push_back(color[i][j]);
  }
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}

Data getBlockData(int cnum) {
  int num = 0;
  double y = 0, x = 0;
  rep(i, H) rep(j, W) {
    if (color[i][j] == cnum) {
      num++;
      y += i + 0.5;
      x += j + 0.5;
    }
  }

  y /= num;
  x /= num;

  return Data(y, x, num);
}

pair<int, int> getBlockHeadX(int col) {
  int xL = 1000, xR = -1;
  rep(i, H) rep(j, W) {
    if (color[i][j] != -1 && color[i][j] != col && in_range(i + 1, j, H, W) &&
        color[i + 1][j] == col) {
      minimize(xL, j);
      maximize(xR, j + 1);
    }
  }
  return make_pair(xL, xR);
}

pair<int, int> getBlockBottomOnBlock(int mycol, int pcol) {
  int xL = 1000, xR = -1;
  int top = -1;
  rep(i, H) rep(j, W) {
    if (color[i][j] != -1 && color[i][j] == mycol && in_range(i + 1, j, H, W) &&
        color[i + 1][j] == pcol) {
      if (top > i) {
        top = i;
        xL = j;
        xR = j + 1;
      } else {
        minimize(xL, j);
        maximize(xR, j + 1);
      }
    }
  }
  return make_pair(xL, xR);
}

bool safeY(double cy, int cnum) {
  bool safe = 0;
  rep(i, H) rep(j, W) {
    if (color[i][j] == cnum) {
      safe |= cy < i;
    }
  }
  return safe;
}

Data rec(int col) {

  auto vc = getChildrenColors(col);

  double y = 0, x = 0;
  int w = 0;
  for (auto u : vc) {
    auto e = rec(u);
    if (e == InvalidData)
      return InvalidData;
    y += e.y * e.w;
    x += e.x * e.w;
    w += e.w;
    auto xlxr = getBlockBottomOnBlock(u, col);
    if (e.x <= xlxr.first || xlxr.second <= e.x)
      return InvalidData;
  }

  if (w > 0) {
    auto xlxr = getBlockHeadX(col);
    double cy = y / w, cx = x / w;
    if (!safeY(cy, col))
      return InvalidData; // topが高いほうが下
    if (cx <= xlxr.first || xlxr.second <= cx)
      return InvalidData;
  }

  auto mydata = getBlockData(col);
  y += mydata.y * mydata.w;
  x += mydata.x * mydata.w;
  w += mydata.w;

  y /= w;
  x /= w;

  return Data(y, x, w);
}

bool solve() {
  int bottomc = -1;
  int xl = -1, xr = -1;

  rep(j, W) if (color[H - 1][j] != -1) {
    bottomc = color[H - 1][j];
    xl = j;
    break;
  }

  for (int j = W - 1; j >= 0; j--)
    if (color[H - 1][j] != -1) {
      xr = j + 1;
      break;
    }

  auto d = rec(bottomc);
  if (d == InvalidData)
    return false;

  return xl < d.x && d.x < xr;
}

int main() {

  while (cin >> W >> H && (W | H)) {
    G.clear();
    G.resize(H);
    rep(i, H) cin >> G[i];
    rep(i, 66) rep(j, 11) color[i][j] = -1;

    K = 0;
    vector<vector<bool>> vis(H, vector<bool>(W));
    rep(i, H) rep(j, W) {
      if (G[i][j] == '.')
        continue;
      if (vis[i][j])
        continue;
      vis[i][j] = 1;
      coloring(i, j, vis);
      K++;
    }

    cout << (solve() ? "STABLE" : "UNSTABLE") << endl;
  }

  return 0;
}