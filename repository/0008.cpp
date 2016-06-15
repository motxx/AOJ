#include <iostream>

using namespace std;

int main(void) {
  int a, b, c, d, n, cnt;

  while (1) {
    cnt = 0;
    cin >> n;

    if (cin.eof()) break;

    for (a = 0; a < 10; a++) {
      for (b = 0; b < 10; b++) {
        for (c = 0; c < 10; c++) {
          for (d = 0; d < 10; d++) {
            if (a + b + c + d == n) {
              cnt++;
            }
          }
        }
      }
    }

    cout << cnt << endl;
  }
  return 0;
}