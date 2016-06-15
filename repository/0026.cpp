#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int G[101][101];

bool inF(int x, int y) { return 0 <= x < 10 && 0 <= y < 10; }

void draw(int x, int y) {
  if (inF(x, y)) {
    G[y][x]++;
  }
}

int main() {
  int a, b, c;
  char d;

  fill(G[0], G[10], 0);

  while (cin >> a >> d >> b >> d >> c) {
    draw(a, b);
    switch (c) {
      case 3:
        draw(a - 2, b);
        draw(a + 2, b);
        draw(a, b - 2);
        draw(a, b + 2);
      case 2:
        draw(a - 1, b - 1);
        draw(a + 1, b - 1);
        draw(a - 1, b + 1);
        draw(a + 1, b + 1);
      case 1:
        draw(a - 1, b);
        draw(a + 1, b);
        draw(a, b - 1);
        draw(a, b + 1);
        break;
    }
  }

  int clrNum = 0, mx = 0;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      mx = max(mx, G[i][j]);
      if (G[i][j] == 0) clrNum++;
    }
  }

  cout << clrNum << endl << mx << endl;

  return 0;
}