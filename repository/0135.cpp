#include <bits/stdc++.h>

using namespace std;

int main() {
  int Tc;
  cin >> Tc;
  int H, M;

  while (Tc--) {
    scanf("%d:%d", &H, &M);

    double h = H * 30.0 + M / 2.0, m = M * 6;

    int ang = abs(h - m);
    if (ang > 180) ang = 360 - ang;
    if (0 <= ang && ang < 30) {
      cout << "alert" << endl;
    } else if (90 <= ang && ang <= 180) {
      cout << "safe" << endl;
    } else
      cout << "warning" << endl;
  }

  return 0;
}