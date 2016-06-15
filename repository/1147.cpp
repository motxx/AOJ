#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int n;
  while (cin >> n, n) {
    int dat[n];
    for (int i = 0; i < n; i++) cin >> dat[i];
    sort(dat, dat + n);
    int ave = 0;
    for (int i = 1; i < n - 1; i++) ave += dat[i];
    ave /= n - 2;
    cout << ave << endl;
  }

  return 0;
}