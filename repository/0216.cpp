#include <iostream>

using namespace std;

int main() {
  int n;
  while (cin >> n && n >= 0) {
    int res = 3130;
    for (int i = 11; i <= n; i++) {
      if (i <= 20)
        res -= 125;
      else if (i <= 30)
        res -= 140;
      else
        res -= 160;
    }
    cout << res << endl;
  }

  return 0;
}