#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;

  while (cin >> n) {
    int m = 100000;
    while (n--) {
      m = ceil(m * 1.05 / 1000) * 1000;
    }
    cout << m << endl;
  }
  return 0;
}