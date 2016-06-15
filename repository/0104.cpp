#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
  char G[200][200];
  bool visited[200][200];
  int W, H;
  string str;

  while (cin >> H >> W) {
    if (W == 0 && H == 0) break;
    for (int i = 0; i < H; i++) {
      cin >> str;
      for (int j = 0; j < W; j++) {
        G[i][j] = str[j];
        visited[i][j] = false;
      }
    }

    int x = 0, y = 0;
    while (1) {
      if (visited[y][x]) {
        cout << "LOOP" << endl;
        break;
      }

      visited[y][x] = true;
      if (G[y][x] == '>')
        x++;
      else if (G[y][x] == 'v')
        y++;
      else if (G[y][x] == '^')
        y--;
      else if (G[y][x] == '<')
        x--;
      else if (G[y][x] == '.') {
        cout << x << " " << y << endl;
        break;
      }
    }
  }

  return 0;
}