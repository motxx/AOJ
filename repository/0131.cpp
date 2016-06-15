#include <cstring>
#include <iostream>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int ori[10][10];
int arr[10][10];
int arr2[10][10];

void flip(int i, int j) {
  arr[i][j] = 1 - arr[i][j];
  arr2[i][j] = 1 - arr2[i][j];
  for (int k = 0; k < 4; k++) {
    int nx = j + dx[k], ny = i + dy[k];
    if (0 <= ny && ny < 10 && 0 <= nx && nx < 10) {
      arr[ny][nx] = 1 - arr[ny][nx];
    }
  }
}

int main() {
  int Tc;
  cin >> Tc;

  while (Tc--) {
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++) cin >> ori[i][j];

    bool good = 0;
    for (int I = 0; I < (1 << 10); I++) {
      memset(arr2, 0, sizeof(arr2));
      memcpy(arr, ori, sizeof(ori));
      bool ok = 1;
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          if (i == 0) {
            if ((I >> j) & 1) {
              if (arr[0][j] == 0) flip(0, j);
            } else {
              if (arr[0][j] == 1) flip(0, j);
            }
          } else {
            if (arr[i - 1][j] == 1) flip(i, j);
          }
        }
      }

      for (int i = 0; i < 10; i++) {
        if (arr[9][i]) ok = 0;
      }
      if (ok) {
        good = 1;
        break;
      }
    }
    if (good) {
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          if (j) cout << " ";
          cout << arr2[i][j];
        }
        cout << endl;
      }
    }
  }

  return 0;
}