#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int z;

  while (cin >> z && z) {
    int mx = 0;
    for (int x = 1; x * x * x <= z * z * z; x++) {
      int y = pow(z * z * z - x * x * x, 1.0 / 3);
      if (y > 0) mx = max(mx, x * x * x + y * y * y);
    }
    cout << z * z * z - mx << endl;
  }

  return 0;
}