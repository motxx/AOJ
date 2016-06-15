#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, q;
  while (cin >> n >> q && (n | q)) {
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        mp[x]++;
      }
    }

    int mx = q - 1;
    int num;
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
      if (mx < it->second) {
        num = it->first;
        mx = it->second;
      }
    }
    if (mx == q - 1)
      cout << 0 << endl;
    else
      cout << num << endl;
  }

  return 0;
}