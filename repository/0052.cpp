#include <iostream>
using namespace std;

int c(int a, int num) {
  int ret = 0;
  while (a % num == 0) {
    ret++;
    a /= num;
  }
  return ret;
}

int main() {
  int n;
  while (cin >> n, n) {
    int t = 0, f = 0;
    for (int i = 2; i <= n; i++) {
      t += c(i, 2);
      f += c(i, 5);
    }
    cout << min(t, f) << endl;
  }
  return 0;
}