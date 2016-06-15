#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int N;
  int x, y, b, p;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> x >> y >> b >> p;
    int a = x * b * 0.8 + y * p * 0.8;

    if (b >= 5 && p >= 2) {
      cout << a << endl;
    } else {
      int tmp = x * b + y * p;
      if (b >= 5 && tmp > (x * b + y * 2) * 0.8)
        cout << (x * b + y * 2) * 0.8 << endl;
      else if (p >= 2 && tmp > (x * 5 + y * p) * 0.8)
        cout << (x * 5 + y * p) * 0.8 << endl;
      else
        cout << tmp << endl;
    }
  }

  return 0;
}