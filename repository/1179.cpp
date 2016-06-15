#include <algorithm>
#include <iostream>

using namespace std;

int compute(int y, int m, int d) {
  int ret = 0;
  int a = (y - 1) / 3;
  int b = (y - 1) - a;
  ret += 200 * a + 195 * b;
  ret += 20 * (m - 1) - (y % 3 == 0 ? 0 : (m - 1) / 2);
  ret += d;
  return ret;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int y, m, d;
    cin >> y >> m >> d;
    cout << compute(1000, 1, 1) - compute(y, m, d) << endl;
  }

  return 0;
}