#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;

  while (cin >> n, n) {
    int a = n;
    int ans = 0;
    for (int st = 1; st < n; st++) {
      a = n;
      for (int i = st; a > 0; i++) a -= i;
      if (a == 0) ans++;
    }
    cout << ans << endl;
  }

  return 0;
}