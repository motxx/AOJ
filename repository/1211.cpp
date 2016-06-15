#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

char in[1002][1001];
map<int, int> ans;

int N;

inline bool valid(int x, int y) {
  return 0 <= x && x < 1001 && 0 <= y && y < N;
}

int getlen_yaxis(int x, int y) {
  int top_y = y;
  while (top_y >= 0 && in[top_y][x] == '*') {
    top_y--;
  }
  top_y++;
  int bottom_y = y;
  while (bottom_y < N && in[bottom_y][x] == '*') {
    bottom_y++;
  }
  bottom_y--;

  return bottom_y - top_y + 1;
}

int getlen_xaxis(int x, int y) {
  int left_x = x;
  while (left_x >= 0 && in[y][left_x] == '*') {
    left_x--;
  }
  left_x++;
  int right_x = x;
  while (right_x < 1001 && in[y][right_x] == '*') {
    right_x++;
  }
  right_x--;

  return right_x - left_x + 1;
}

int const dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int const dy[8] = {0, -1, 0, 1, -1, -1, 1, 1};

void move_to_xaxis(int& x, int& y) {
  int dir;
  if (x - 1 >= 0 && in[y][x - 1] == '*') {
    dir = 0;
  } else {
    dir = 2;
  }

  bool turn = 0;
  while (1) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (valid(nx, ny) && in[ny][nx] == '*') {
      if (turn && (x + 1 == nx || x - 1 == nx) && y == ny) return;
      x = nx, y = ny;
    } else {
      rep(k, 8) {
        nx = x + dx[k], ny = y + dy[k];
        if (x - dx[dir] == nx && y - dy[dir] == ny) continue;
        if (valid(nx, ny) && in[ny][nx] == '*' &&
            valid(nx + dx[k], ny + dy[k]) &&
            in[ny + dy[k]][nx + dx[k]] == '*') {
          x = nx, y = ny;
          dir = k;
          turn = 1;
          break;
        }
      }
    }
  }
}

void move_to_yaxis(int& x, int& y) {
  int dir;
  if (y - 1 >= 0 && in[y - 1][x] == '*') {
    dir = 1;
  } else {
    dir = 3;
  }

  bool turn = 0;
  while (1) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (valid(nx, ny) && in[ny][nx] == '*') {
      if (turn && (y + 1 == ny || y - 1 == ny) && x == nx) return;
      x = nx, y = ny;
    } else {
      rep(k, 8) {
        nx = x + dx[k], ny = y + dy[k];
        if (x - dx[dir] == nx && y - dy[dir] == ny) continue;
        if (valid(nx, ny) && in[ny][nx] == '*' &&
            valid(nx + dx[k], ny + dy[k]) &&
            in[ny + dy[k]][nx + dx[k]] == '*') {
          x = nx, y = ny;
          dir = k;
          turn = 1;
          break;
        }
      }
    }
  }
}

void calc_area_xaxis(int x, int y) {
  int len1 = getlen_xaxis(x, y);
  int tmp_y = y;
  move_to_xaxis(x, y);
  int len2 = getlen_xaxis(x, y);
  ans[(len1 + len2) * abs(y - tmp_y + 1) / 2]++;
}

void calc_area_yaxis(int x, int y) {
  int len1 = getlen_yaxis(x, y);
  int tmp_x = x;
  move_to_yaxis(x, y);
  int len2 = getlen_yaxis(x, y);
  ans[(len1 + len2) * abs(x - tmp_x + 1) / 2]++;
}

void eraser(int x, int y, int dir) {
  in[y][x] = ' ';

  while (1) {
    int nx = x + dx[dir], ny = y + dy[dir];
    if (valid(nx, ny) && in[ny][nx] == '*') {
      in[ny][nx] = ' ';
      x = nx, y = ny;
    } else {
      bool changed = 0;
      rep(k, 8) {
        int nx = x + dx[k], ny = y + dy[k];
        if (valid(nx, ny) && in[ny][nx] == '*' &&
            valid(nx + dx[k], ny + dy[k]) &&
            in[ny + dy[k]][nx + dx[k]] == '*') {
          in[ny][nx] = ' ';
          x = nx, y = ny;
          dir = k;
          changed = 1;
          break;
        }
      }
      if (!changed) {
        rep(k, 8) {
          int nx = x + dx[k], ny = y + dy[k];
          if (!valid(nx, ny)) continue;
          in[ny][nx] = ' ';
        }
        break;
      }
    }
  }
}

int main() {
  while (cin >> N && N) {
    ans.clear();
    memset(in, 0, sizeof in);
    cin.ignore();
    rep(i, N) {
      rep(j, 1001) {
        char c;
        scanf("%c", &c);
        if (c == '\n') {
          break;
        }
        in[i][j] = c;
      }
    }

    rep(i, N) {
      rep(j, 1001) {
        if (in[i][j] == 0) break;
        if (in[i][j] == '*' && (j - 1 >= 0 && in[i][j - 1] == '*')) {
          calc_area_xaxis(j, i);
          eraser(j, i, 0);
        } else if (in[i][j] == '*' && (i - 1 >= 0 && in[i - 1][j] == '*')) {
          calc_area_yaxis(j, i);
          eraser(j, i, 1);
        }
      }
    }
    static bool flag = 0;
    if (flag) cout << "----------\n";
    flag = 1;
    map<int, int>::iterator it = ans.begin();
    for (; it != ans.end(); it++) {
      cout << it->first << ' ' << it->second << endl;
    }
  }

  return 0;
}