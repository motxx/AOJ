#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e;
  int list[100];
  int n;
  int x;
  while (cin >> x && x) {
    int i;
    for (i = 0; i < x; i++) {
      cin >> a >> b >> c >> d >> e;
      list[i] = a + b + c + d + e;
    }
    n = i;
    sort(list, list + n);
    cout << list[n - 1] << ' ' << list[0] << endl;
  }
  return 0;
}