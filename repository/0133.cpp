#include <iostream>
using namespace std;

char M[4][8][8];

void rotate90AndDisp(int k) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      M[k + 1][i][j] = M[k][7 - j][i];
      cout << M[k + 1][i][j];
    }
    cout << endl;
  }
}

int main() {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) cin >> M[0][i][j];

  for (int k = 0; k < 3; k++) {
    cout << 90 * (k + 1) << endl;
    rotate90AndDisp(k);
  }

  return 0;
}