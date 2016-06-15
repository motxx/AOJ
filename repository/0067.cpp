#include <iostream>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

char M[12][12];

void dfs(int sx, int sy) {
  M[sy][sx] = '0';
  for (int i = 0; i < 4; i++) {
    int nx = sx + dx[i], ny = sy + dy[i];
    if (0 <= nx && nx < 12 && 0 <= ny && ny < 12 && M[ny][nx] - '0')
      dfs(nx, ny);
  }
}

int main() {
  int m;
  string s;

  while (1) {
    if (!(cin >> M[0][0])) break;

    for (int i = 0; i < 12; i++)
      for (int j = 0; j < 12; j++) {
        if (i == 0 && j == 0) continue;
        cin >> M[i][j];
      }

    m = 0;
    for (int i = 0; i < 12; i++) {
      for (int j = 0; j < 12; j++) {
        if (M[i][j] - '0') {
          dfs(j, i);
          m++;
        }
      }
    }
    cout << m << endl;
  }

  return 0;
}