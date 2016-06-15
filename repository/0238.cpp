#include <iostream>
using namespace std;
int d, n, s, t, sum;
int main() {
  while (cin >> d >> n, d) {
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> s >> t;
      sum += t - s;
    }
    if (sum < d)
      cout << d - sum << endl;
    else
      cout << "OK" << endl;
  }

  return 0;
}