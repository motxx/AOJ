#include <iostream>
using namespace std;

int main() {
  int l, m, n;
  while (cin >> l && l) {
    int ans = -1;
    for (int i = 0; i < 12; i++) {
      cin >> m >> n;
      l -= m - n;
      if (ans == -1 && l <= 0) {
        ans = i + 1;
      }
    }
    if (ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }

  return 0;
}