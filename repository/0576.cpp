#include <iostream>

using namespace std;

int main(void) {
  int l;
  int a, b;
  int c, d;
  int i;

  cin >> l >> a >> b >> c >> d;

  for (i = 1;; i++) {
    a -= c;
    b -= d;
    if (a <= 0 && b <= 0) break;
  }

  cout << l - i << endl;

  return 0;
}