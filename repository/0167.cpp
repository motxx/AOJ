#include <algorithm>
#include <iostream>
using namespace std;
main() {
  for (int n; cin >> n, n;) {
    int dat[100];
    for (int i = 0; i < n; i++) cin >> dat[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
      for (int j = n - 1; j > i; j--)
        if (dat[j - 1] > dat[j]) swap(dat[j - 1], dat[j]), ans++;
    cout << ans << endl;
  }
}