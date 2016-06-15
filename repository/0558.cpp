#include <memory.h>
#include <stdbool.h>
#include <stdio.h>

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int c[1000][1000];
int dat[1000][1000];
int cost[1000][1000];
int destination = 1;
int startposx, startposy;
int h, w, n;

struct QUEUE {
  int x, y;
};
QUEUE queue[1000000];
int qbegin = 0, qend = 0;

void bfsToDestination(int x, int y);
void PushQueue(int x, int y);
QUEUE PopQueue();
bool isQueueEmpty();

int main(void) {
  int i, j;

  scanf("%d%d%d", &h, &w, &n);

  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      dat[j][i] = fgetc(stdin);
      if (dat[j][i] == '\n') dat[j][i] = fgetc(stdin);
      if (dat[j][i] == 'S') {
        startposx = j;
        startposy = i;
        cost[j][i] = 0;
      }
    }
  }

  // for(i = 0; i < h; i++) {
  //  for(j = 0; j < w; j++) {
  //    printf("%c", dat[j][i]);
  //  }
  //  printf("\n");
  //}

  for (i = 0; i < n; i++) {
    memcpy(c, dat, sizeof(dat));
    bfsToDestination(startposx, startposy);
  }

  printf("%d\n", cost[startposx][startposy]);

  return 0;
}

void bfsToDestination(int x, int y) {
  int i;
  QUEUE ret;

  qbegin = 0;
  qend = 0;

  // map
  // int j;
  // printf("---map\n");
  // for(i = 0; i < h; i++) {
  //  for(j = 0; j < w; j++) {
  //    printf("%c", c[j][i]);
  //  }
  //  printf("\n");
  //}

  PushQueue(x, y);
  c[x][y] = 'X';

  while (!isQueueEmpty()) {
    ret = PopQueue();

    // printf("ret.x:%d ret.y:%d cost.x,y:%d\n", ret.x, ret.y,
    // cost[ret.x][ret.y]);

    for (i = 0; i < 4; i++) {
      int nx = ret.x + dx[i];
      int ny = ret.y + dy[i];

      if ((nx >= 0) && (ny >= 0) && (nx < w) && (ny < h)) {
        if (c[nx][ny] != 'X') {
          PushQueue(nx, ny);
          cost[nx][ny] = cost[ret.x][ret.y] + 1;
          if ((c[nx][ny] - '0') == destination) {
            destination++;
            startposx = nx;
            startposy = ny;
            return;
          }
          c[nx][ny] = 'X';
        }
      }
    }
  }
}

void PushQueue(int x, int y) {
  queue[qend].x = x;
  queue[qend].y = y;
  qend++;
}

QUEUE PopQueue() {
  QUEUE ret;
  ret.x = queue[qbegin].x;
  ret.y = queue[qbegin].y;
  qbegin++;

  return ret;
}

bool isQueueEmpty() {
  if (qend == qbegin) return true;

  return false;
}