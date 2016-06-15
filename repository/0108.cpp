#include <iostream>
#include <map>
using namespace std;

int main() {
  int n;
  int a[12], b[12];
  map<int, int> mp;

  while (cin >> n, n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    while (1) {
      mp.clear();
      for (int i = 0; i < n; i++) mp[a[i]]++;
      for (int i = 0; i < n; i++) b[i] = mp[a[i]];

      bool fin = true;
      for (int i = 0; i < n; i++)
        if (a[i] != b[i]) fin = false;
      if (fin) break;
      cnt++;
      for (int i = 0; i < n; i++) a[i] = b[i];
    }

    cout << cnt << endl;
    for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
    cout << a[n - 1] << endl;
  }

  return 0;
}