#include <bits/stdc++.h>

using namespace std;

// container utility
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PB push_back

// rep
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)

int check(char grid[2][2]) {
  if (grid[0][0] == '#' && grid[0][1] == '.' && grid[1][0] == '.' &&
      grid[1][1] == '.') {
    return +1;
  }

  if (grid[0][0] == '.' && grid[0][1] == '#' && grid[1][0] == '#' &&
      grid[1][1] == '#') {
    return +1;
  }

  if (grid[0][0] == '#' && grid[0][1] == '#' && grid[1][0] == '#' &&
      grid[1][1] == '.') {
    return -1;
  }

  if (grid[0][0] == '.' && grid[0][1] == '.' && grid[1][0] == '.' &&
      grid[1][1] == '#') {
    return -1;
  }

  return 0;
}

int main() {
  int H, W;
  while (cin >> H >> W) {
    H += 2, W += 2;
    vector<vector<char>> G(H, vector<char>(W, '.'));
    REP(i, 1, H - 1) {
      REP(j, 1, W - 1) { cin >> G[i][j]; }
    }

    vector<pair<double, int>> event;

    rep(i, H - 1) {
      rep(j, W - 1) {
        char grid[2][2];
        grid[0][0] = G[i][j];
        grid[0][1] = G[i][j + 1];
        grid[1][0] = G[i + 1][j];
        grid[1][1] = G[i + 1][j + 1];

        int num = check(grid);
        if (num != 0) {
          double ang = atan2((H - 2) - i, j);
          event.PB(MP(atan2((H - 2) - i, j), num));
        }
      }
    }

    sort(ALL(event));

    int mx = 2;
    int cnt = 1;
    for (auto e : event) {
      cnt += e.second;
      mx = max(mx, cnt);
    }
    cout << mx << endl;
  }

  return 0;
}