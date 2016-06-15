#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  int n;

  while (cin >> a >> b >> n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
      a = a % b * 10;
      s += a / b;
    }

    cout << s << endl;
  }

  return 0;
}