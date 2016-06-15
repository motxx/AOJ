#include <iostream>
using namespace std;
int main() {
  int t, a, d, c;
  while (cin >> a >> d, (a | d)) {
    t = a + d;
    c = 0;
    for (int i = 1; i < 5; i++) {
      cin >> a >> d;
      if (t < a + d) t = a + d, c = i;
    }
    cout << (char)(c + 'A') << ' ' << t << endl;
  }
  return 0;
}