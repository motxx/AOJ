#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 0; i < 10; i++) {
      if (n & 1) {
        cout << (1 << i);
        if (n >> 1) cout << " ";
      }
      n >>= 1;
    }
    cout << endl;
  }
  return 0;
}