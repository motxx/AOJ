#include <algorithm>
#include <iostream>
using namespace std;

double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;

bool isOverlap() {
  // x, y に関して大きいほうが小さい方より大きい
  if (min(xa1, xa2) <= max(xb1, xb2) && min(xb1, xb2) <= max(xa1, xa2)) {
    if (min(ya1, ya2) <= max(yb1, yb2) && min(yb1, yb2) <= max(ya1, ya2))
      return true;
  }
  return false;
}

int main() {
  while (cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2) {
    if (isOverlap())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}