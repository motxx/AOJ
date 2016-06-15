#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    if (n % 39 == 0)
      cout << "3C39" << endl;
    else
      printf("3C%02d\n", n % 39);
  }
  return 0;
}