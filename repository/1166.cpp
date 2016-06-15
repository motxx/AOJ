#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
#define L 2
#define U 3
#define R 0
#define D 1

int cost[40][40];
bool wall[5][40][40];
bool visited[40][40];
int w, h;

int bfs(int sx, int sy, int gx, int gy) {
  fill(cost[0], cost[32], 0);
  fill(visited[0], visited[32], false);
  cost[0][0] = 1;

  queue<pair<int, int> > Q;
  Q.push(make_pair(0, 0));
  visited[0][0] = true;
  while (!Q.empty()) {
    pair<int, int> st = Q.front();
    Q.pop();

    if (st.first == gx && st.second == gy) {
      return cost[gy][gx];
    }

    for (int i = 0; i < 4; i++) {
      int nx = st.first + dx[i], ny = st.second + dy[i];
      if (0 <= nx && nx < w && 0 <= ny && ny < h) {
        if (!visited[ny][nx] && !wall[i][st.second][st.first]) {
          visited[ny][nx] = true;
          cost[ny][nx] = cost[st.second][st.first] + 1;
          Q.push(make_pair(nx, ny));
        }
      }
    }
  }
  return 0;
}

int main() {
  while (cin >> w >> h && w + h) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 32; j++)
        for (int k = 0; k < 32; k++) wall[i][j][k] = 0;

    for (int i = 0; i < h; i++) {
      wall[R][i][0] = wall[L][i][w - 1] = 1;
    }
    for (int i = 0; i < w; i++) {
      wall[D][0][i] = wall[U][h - 1][i] = 1;
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w - 1; j++) {
        cin >> wall[L][i][j];
        wall[R][i][j + 1] = wall[L][i][j];
      }

      if (i < h - 1) {
        for (int j = 0; j < w; j++) {
          cin >> wall[U][i][j];
          wall[D][i + 1][j] = wall[U][i][j];
        }
      }
    }

    /*
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++) {
        cout << "R: " << wall[R][i][j] << " L: " << wall[L][i][j] << " U: " <<
    wall[U][i][j] << " D: " << wall[D][i][j] << endl;
      }
    }
    */

    cout << bfs(0, 0, w - 1, h - 1) << endl;
    /*
    for(int i=0; i<h; i++) {
      for(int j=0; j<w; j++)
        cout << cost[i][j] << " ";
      cout << endl;
    }
    */
  }

  return 0;
}