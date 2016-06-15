#include <iostream>
using namespace std;

int M[15][15];
int temp[15][15];
int n, m;

bool in(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n; }

void dfs(int y, int x, int bit) {
  const int dx[] = {-1, 1, 0, 0};
  const int dy[] = {0, 0, -1, 1};
  M[y][x] = 1 - M[y][x];
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (in(nx, ny) && M[ny][nx] == bit) dfs(ny, nx, bit);
  }
}

void island_rev(int r, int c) {
  r--, c--;
  dfs(r, c, M[r][c]);
}

void leftshift(int r) {
  r--;
  int tmp = M[r][0];
  for (int i = 0; i < n - 1; i++) {
    M[r][i] = M[r][i + 1];
  }
  M[r][n - 1] = tmp;
}

void rightshift(int r) {
  r--;
  int tmp = M[r][n - 1];
  for (int i = n - 1; i >= 1; i--) {
    M[r][i] = M[r][i - 1];
  }
  M[r][0] = tmp;
}

void reversal(int r, int c, int sz) {
  r--, c--;
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      M[r + i][c + j] = 1 - M[r + i][c + j];
    }
  }
}

void rotate90(int r, int c, int sz) {
  r--, c--;
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      temp[i][j] = M[r + i][c + j];
    }
  }

  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      M[r + i][c + j] = temp[sz - 1 - j][i];
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
    }
  }

  int op, r, c, sz, ang;

  while (m--) {
    cin >> op;
    if (op == 0) {
      cin >> r >> c >> sz >> ang;
      for (int i = 0; i < ang; i += 90) rotate90(r, c, sz);
    }
    if (op == 1) {
      cin >> r >> c >> sz;
      reversal(r, c, sz);
    }
    if (op == 2) {
      cin >> r;
      leftshift(r);
    }
    if (op == 3) {
      cin >> r;
      rightshift(r);
    }
    if (op == 4) {
      cin >> r >> c;
      island_rev(r, c);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j)
        cout << " " << M[i][j];
      else
        cout << M[i][j];
    }
    cout << endl;
  }

  return 0;
}