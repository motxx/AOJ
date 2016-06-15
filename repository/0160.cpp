#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n && n) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x, y, h, w;
      cin >> x >> y >> h >> w;
      x += y + h;
      if (x <= 60 && w <= 2)
        ans += 6;
      else if (x <= 80 && w <= 5)
        ans += 8;
      else if (x <= 100 && w <= 10)
        ans += 10;
      else if (x <= 120 && w <= 15)
        ans += 12;
      else if (x <= 140 && w <= 20)
        ans += 14;
      else if (x <= 160 && w <= 25)
        ans += 16;
    }
    cout << ans * 100 << endl;
  }
  return 0;
}