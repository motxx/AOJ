#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  char fir, sec, ch;
  char a = 'A', b = 'B', c = 'C';
  while (cin >> fir >> ch >> sec) {
    if (a == fir && b == sec)
      swap(a, b);
    else if (b == fir && c == sec)
      swap(b, c);
    else if (c == fir && a == sec)
      swap(c, a);
    else if (b == fir && a == sec)
      swap(a, b);
    else if (c == fir && b == sec)
      swap(b, c);
    else if (a == fir && c == sec)
      swap(c, a);
  }
  cout << a << endl;

  return 0;
}