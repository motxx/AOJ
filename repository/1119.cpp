#include <cmath>
#include <iostream>
using namespace std;
int main() {
  int n, cnt = 0;
  double x = 0, y = 0;
  double trX = 0, trY = 0;
  double dx, dy;
  double ret = 0;

  cin >> n;
  while (cin >> dx >> dy) {
    x += dx, y += dy;
    double temp = max(ret, sqrt(x * x + y * y));
    if (temp == sqrt(x * x + y * y)) {
      if (ret < temp) {
        ret = temp;
        trX = x, trY = y;
        // cout << "cX:" << x << " cY:" << y << endl;
      } else if (trX <= x) {
        trX = x, trY = y;
        // cout << "trX:" << trX << " trY:" << trY << endl;
      }
    }
    if (dx == 0 && dy == 0) {
      cout << trX << " " << trY << endl;
      cnt++;
      if (cnt == n) break;
      x = 0, y = 0;
      trX = 0, trY = 0;
      ret = 0;
    }
  }

  return 0;
}