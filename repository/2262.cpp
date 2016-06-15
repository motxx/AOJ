#include <cctype>
#include <iostream>
#include <string>
using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

const int MAX_H = 20;
const int MAX_W = 20;
const int MAX_M = 16;

int H, W;
string M[MAX_H];
bool vis[MAX_M][4][MAX_H][MAX_W];

bool run(int x, int y, int dir, int mem) {
  if (vis[mem][dir][y][x]) return 0;
  vis[mem][dir][y][x] = 1;

  switch (M[y][x]) {
    case '<':
      dir = 0;
      break;
    case '>':
      dir = 2;
      break;
    case '^':
      dir = 1;
      break;
    case 'v':
      dir = 3;
      break;
    case '_':
      dir = (mem ? 0 : 2);
      break;
    case '|':
      dir = (mem ? 1 : 3);
      break;
    case '.':
      break;
    case '@':
      return 1;
    case '+':
      mem = (mem + 1) % 16;
      break;
    case '-':
      mem = (mem + 15) % 16;
      break;
    case '?':
      for (int i = 0; i < 4; i++) {
        if (run((x + dx[i] + W) % W, (y + dy[i] + H) % H, i, mem)) return 1;
      }
      return 0;
    default:
      if (isdigit(M[y][x])) {
        mem = M[y][x] - '0';
      }
  }
  return run((x + dx[dir] + W) % W, (y + dy[dir] + H) % H, dir, mem);
}

int main() {
  cin >> H >> W;
  cin.ignore();

  for (int i = 0; i < H; i++) getline(cin, M[i]);

  if (run(0, 0, 2, 0))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}