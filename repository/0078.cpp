#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
  int n;
  int mat[16][16];

  while (scanf("%d", &n), n) {
    fill(mat[0], mat[15], 0);
    int x = n / 2, y = n / 2 + 1;
    for (int i = 0; i < n * n; i++) {
      if (mat[y][x]) x = (x + n - 1) % n, y = (y + 1) % n;
      mat[y][x] = i + 1;
      x = (x + 1) % n, y = (y + 1) % n;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%4d", mat[i][j]);
      }
      printf("\n");
    }
  }

  return 0;
}