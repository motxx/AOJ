#include <stdio.h>

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};
int c[50][50];
int h, w;

void dfs(int x, int y);

int main(void) {
  int i, j;
  int linenum;

  while (1) {
    scanf("%d%d", &w, &h);

    if ((w == 0) && (h == 0)) return 0;

    // syokika
    linenum = 0;

    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        scanf("%d", &c[i][j]);
      }
    }

    // dfs
    for (i = 0; i < h; i++) {
      for (j = 0; j < w; j++) {
        if (c[i][j] == 1) {
          dfs(j, i);
          linenum++;
        }
      }
    }

    printf("%d\n", linenum);
  }

  return 0;
}

void dfs(int x, int y) {
  int i;
  int j;

  c[y][x] = 0;

  for (i = 0; i < 8; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if ((nx >= 0) && (ny >= 0) && (nx < w) && (ny < h)) {
      if (c[ny][nx] == 1) {
        dfs(nx, ny);
      }
    }
  }
}