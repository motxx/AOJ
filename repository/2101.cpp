#include <iostream>
using namespace std;

int main() {
  int n;

  while (cin >> n, n) {
    int perfectNumber = 0;

    for (int i = 1; i * i < n; i++) {
      if (n % i == 0) {
        perfectNumber += n / i;
        perfectNumber += i;
      }
    }
    perfectNumber -= n;
    if (perfectNumber < n)
      cout << "deficient number" << endl;
    else if (perfectNumber == n)
      cout << "perfect number" << endl;
    else
      cout << "abundant number" << endl;
  }

  return 0;
}