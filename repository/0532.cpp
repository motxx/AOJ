#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int h, m, s, hh, mm, ss; cin >> h >> m >> s >> hh >> mm >> ss;) {
    int d = hh * 3600 + mm * 60 + ss - h * 3600 - m * 60 - s;
    cout << d / 3600 << ' ' << (d - (d / 3600 * 3600)) / 60 << ' '
         << d - d / 3600 * 3600 - ((d - (d / 3600 * 3600)) / 60 * 60) << endl;
  }
  return 0;
}