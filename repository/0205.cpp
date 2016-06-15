#include <iostream>
using namespace std;

int main() {
  int a[5];
  while (cin >> a[0] && a[0]) {
    for (int i = 1; i < 5; i++) cin >> a[i];
    for (int i = 0; i < 5; i++) {
      int win = 0, lose = 0;
      for (int j = 0; j < 5; j++) {
        if (a[i] % 3 == a[j] - 1) win++;
        if (a[j] % 3 == a[i] - 1) lose++;
      }
      int res;
      if (win && lose == 0)
        res = 1;
      else if (win == 0 && lose)
        res = 2;
      else
        res = 3;
      cout << res << endl;
    }
  }

  return 0;
}