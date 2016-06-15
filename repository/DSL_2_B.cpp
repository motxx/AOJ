#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 100000

int bit[MAX_N + 1], n;

int sum(int i) {
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x) {
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

int main() {
  int q;
  int com, x, y;
  cin >> n >> q;
  while (q--) {
    cin >> com >> x >> y;
    if (com == 0) {
      add(x, y);
    } else {
      cout << sum(y) - sum(x - 1) << endl;
    }
  }
  return 0;
}