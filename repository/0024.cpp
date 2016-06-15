#include <cmath>
#include <iostream>

using namespace std;
int main() {
  double v;

  while (cin >> v) {
    double t = v / 9.8;
    double y = 4.9 * t * t;
    cout << ceil((y + 5) / 5) << endl;
  }

  return 0;
}