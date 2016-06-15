#include <iostream>
using namespace std;
int main() {
  int Tc;
  cin >> Tc;
  while (Tc--) {
    int n;
    cin >> n;
    int a = 0, b = 0;
    int prev;
    cin >> prev;
    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      if (prev - x >= 0) {
        a = max(a, prev - x);
      } else {
        b = max(b, x - prev);
      }
      prev = x;
    }
    cout << b << " " << a << endl;
  }
  return 0;
}