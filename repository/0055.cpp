#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  double d;
  while (cin >> d) {
    double a[10], s = 0;
    a[0] = s = d;
    for (int i = 0; i < 9; i++) {
      if (i % 2)
        a[i + 1] = a[i] / 3;
      else
        a[i + 1] = a[i] * 2;
      s += a[i + 1];
    }
    cout << setprecision(10) << s << endl;
  }
  return 0;
}