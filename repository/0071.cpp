#include <iostream>
using namespace std;

string M[8];

void dfs(int x, int y) {
  M[y][x] = '0';
  for (int i = -3; i <= 3; i++) {
    if (i && 0 <= x + i && x + i < 8 && M[y][x + i] - '0') dfs(x + i, y);
  }
  for (int i = -3; i <= 3; i++) {
    if (i && 0 <= y + i && y + i < 8 && M[y + i][x] - '0') dfs(x, y + i);
  }
}

int main() {
  int n;

  cin >> n;
  for (int k = 0; k < n; k++) {
    cin.ignore();
    cin.ignore();
    for (int i = 0; i < 8; i++) getline(cin, M[i]);
    int x, y;
    cin >> x >> y;
    x--, y--;
    dfs(x, y);
    cout << "Data " << k + 1 << ":" << endl;
    for (int i = 0; i < 8; i++) cout << M[i] << endl;
  }
  return 0;
}