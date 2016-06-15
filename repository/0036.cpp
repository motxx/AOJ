#include <iostream>
#include <string>
using namespace std;

string M[8];

bool inF(int y, int x) { return 0 <= x && x < 8 && 0 <= y && y < 8; }

int main() {
  while (cin >> M[0]) {
    for (int i = 1; i < 8; i++) cin >> M[i];

    char res = '#';

    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (M[i][j] - '0') {
          if (inF(i + 1, j + 1) && M[i + 1][j + 1] - '0') {
            if (inF(i + 2, j + 1) && M[i + 2][j + 1] - '0') {
              res = 'F';
              goto end;
            } else if (inF(i + 1, j + 2) && M[i + 1][j + 2] - '0') {
              res = 'E';
              goto end;
            } else {
              res = 'A';
              goto end;
            }
          }

          if (inF(i + 3, j) && M[i + 3][j] - '0') {
            res = 'B';
            goto end;
          }

          if (inF(i, j + 3) && M[i][j + 3] - '0') {
            res = 'C';
            goto end;
          }

          if (inF(i + 1, j - 1) && M[i + 1][j - 1] - '0') {
            if (inF(i, j + 1) && M[i][j + 1] - '0') {
              res = 'G';
              goto end;
            } else {
              res = 'D';
              goto end;
            }
          }
        }
      }
    }
  end:
    cout << res << endl;
  }
  return 0;
}