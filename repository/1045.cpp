#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;

  while (cin >> n, n) {
    int data[20] = {}, all = 0;
    for (int i = 0; i < n; i++) {
      cin >> data[i];
      all += data[i];
    }

    int ans = 1 << 23;
    for (int i = 0; i < (1 << n); i++) {
      int a = 0;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          a += data[j];
          ans = min(ans, abs(a - (all - a)));
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}