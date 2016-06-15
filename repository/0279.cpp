#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int n;
  int a[10001];

  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (a[i] - 2 >= 0) ok = true;
    }

    int cnt = 0;
    if (ok) {
      for (int i = 0; i < n; i++)
        if (a[i] > 0) cnt++;
      cout << cnt + 1 << endl;
    } else {
      cout << "NA" << endl;
    }
  }

  return 0;
}