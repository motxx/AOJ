#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int grid[30][30];

inline bool isAtObstacle(int x, int y) { return grid[y][x] == 1; }

inline bool isAtSkiJump(int x, int y) { return grid[y][x] == 2; }

int main() {
  int n, m;

  while (cin >> m >> n && n) {
    fill(grid[0], grid[0] + 900, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    int dp[30][30][2] = {{{}}};

    for (int j = 0; j < m; j++) {
      if (grid[0][j] == 0) {
        dp[0][j][0] = 1;
      }
    }

    int extra = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        // there is no case such that skier is at obstacle.
        if (isAtObstacle(j, i)) continue;

        // A skier is at a ski jump.
        if (isAtSkiJump(j, i)) {
          if (i + 2 > n - 1)
            extra += dp[i][j][0];
          else {
            if (isAtObstacle(j, i + 2)) continue;
            dp[i + 2][j][0] += dp[i][j][0];
          }
        }

        // skiing without jump.
        else {
          // from the upper left
          if (j - 1 >= 0 && !isAtObstacle(j - 1, i + 1) &&
              !isAtSkiJump(j - 1, i + 1)) {
            dp[i + 1][j - 1][1] += dp[i][j][0] + dp[i][j][1];
          }

          // from the above
          if (!isAtObstacle(j, i + 1)) {
            dp[i + 1][j][0] += dp[i][j][0] + dp[i][j][1];
          }

          // from the upper right
          if (j + 1 < m && !isAtObstacle(j + 1, i + 1) &&
              !isAtSkiJump(j + 1, i + 1)) {
            dp[i + 1][j + 1][1] += dp[i][j][0] + dp[i][j][1];
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
      ans += dp[n - 1][i][0] + dp[n - 1][i][1];
    }

    cout << ans + extra << endl;
  }

  return 0;
}