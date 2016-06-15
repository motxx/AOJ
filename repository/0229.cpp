#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  while (1) {
    int b, r, g, c, s, t;
    cin >> b >> r >> g >> c >> s >> t;
    if (!(b | r | g | c | s | t)) break;
    int B = b * 5 + r * 3;
    cout << (100 + B * 15 - B * 2 + g * 7 + c * 2 + (b + r) * 15 -
             (t - s - B) * 3)
         << endl;
  }
  return 0;
}