#include <iostream>
using namespace std;

int H, W;
char str[101][101];

bool in(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

void dfs(int x, int y, char key) {
  /*
    for(int i=0; i<H; i++) {
      for(int j=0; j<W; j++) {
        cout << str[i][j];
      }
      cout << endl;
    }
    cout << endl;
  */
  const int dx[] = {-1, 1, 0, 0};
  const int dy[] = {0, 0, -1, 1};

  str[y][x] = '-';
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (in(nx, ny) && str[ny][nx] == key && str[ny][nx] != '-')
      dfs(nx, ny, key);
  }
}

int main() {
  int n, m;

  while (cin >> n >> m && (n | m)) {
    H = n, W = m;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> str[i][j];

    int ans = 0;
    char key;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (str[i][j] != '-') {
          key = str[i][j];
          dfs(j, i, key);
          ans++;
        }
      }
    }
    /*
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        cout << str[i][j];
      }
      cout << endl;
    }
    */
    cout << ans << endl;
  }

  return 0;
}