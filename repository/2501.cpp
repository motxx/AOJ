#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--;
  b--;
  c--;
  d--;
  int ans = (int)10e9;
  for (int w = 1; w <= n; w++) {
    int man_ab = abs(a % w - b % w) + abs(a / w - b / w);
    int man_cd = abs(c % w - d % w) + abs(c / w - d / w);
    ans = min(ans, man_ab + man_cd);
  }
  cout << ans << endl;
  return 0;
}