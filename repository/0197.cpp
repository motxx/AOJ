#include <algorithm>
#include <iostream>
using namespace std;

int step;

int gcd(int a, int b) {
  if (b == 0) return a;
  step++;
  return gcd(b, a % b);
}

int main() {
  int a, b;

  while (cin >> a >> b, a + b) {
    step = 0;
    if (a < b) swap(a, b);
    cout << gcd(a, b);
    cout << " " << step << endl;
  }

  return 0;
}