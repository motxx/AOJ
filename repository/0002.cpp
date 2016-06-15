#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main(void) {
  int a, b, c;
  char dummy[8];

  while (1) {
    cin >> a >> b;

    if (cin.eof()) return 0;

    c = a + b;

    cout << sprintf(dummy, "%d", c) << endl;
  }
  return 0;
}