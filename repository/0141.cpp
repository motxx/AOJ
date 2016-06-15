#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int Tc;
  cin >> Tc;
  bool a = 0;
  while (Tc--) {
    int N;
    cin >> N;
    if (a) cout << endl;
    a = 1;

    char grid[N + 2][N + 2];
    for (int i = 0; i < N; i++) {
      fill(grid[i], grid[i] + N, ' ');
      grid[i][N] = '\0';
    }

    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {-1, 0, 1, 0};

    int x = 0, y = N;
    int n = N;
    for (int i = 0; i < N; i++) {
      for (int l = 0; l < n; l++) {
        y += dy[i % 4], x += dx[i % 4];
        grid[y][x] = '#';
      }
      if (i % 2 == 0 && i >= 2) n -= 2;
      if (i % 4 == 0) x--;
      if (i % 4 == 1) y--;
      if (i % 4 == 2) x++;
      if (i % 4 == 3) y++;
    }

    for (int i = 0; i < N; i++) {
      cout << grid[i] << endl;
    }
  }

  return 0;
}