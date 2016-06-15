#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n, n) {
    int a, s = 0;
    for (int i = 0; i < n / 4; i++) {
      cin >> a;
      s += a;
    }
    cout << s << endl;
  }
  return 0;
}