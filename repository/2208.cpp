#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n;
  int w[10000], h[10000];
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n, greater<int>());

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (w[j]) w[j]--, h[i]--;

    bool ok = 1;
    for (int i = 0; i < n; i++)
      if (h[i]) {
        ok = 0;
      }

    if (ok)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}