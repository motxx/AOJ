#include <iostream>

using namespace std;

int main() {
  int n;
  int i;
  while (cin >> n && n) {
    for (i = 0; n != 1; i++)
      if (n % 2)
        n = n * 3 + 1;
      else
        n /= 2;
    cout << i << endl;
  }

  return 0;
}