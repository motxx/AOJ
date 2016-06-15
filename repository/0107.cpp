#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int c[3], n, a;

  while (1) {
    for (int i = 0; i < 3; i++) cin >> c[i];
    if (c[0] == 0) break;

    sort(c, c + 3);

    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a;
      cout << ((sqrt(c[0] * c[0] + c[1] * c[1]) < 2 * a) ? "OK" : "NA") << endl;
    }
  }
  return 0;
}