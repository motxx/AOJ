#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<string, int> mp;

int main() {
  int n, p, m, k;
  string s, t;

  while (cin >> n, n) {
    mp.clear();
    for (int i = 0; i < n; i++) {
      cin >> s >> p;
      mp[s] = p;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> s >> k;
      int temp = 0;
      for (int j = 0; j < k; j++) {
        cin >> t;
        temp += mp[t];
      }
      if (temp < mp[s]) mp[s] = temp;
    }

    cin >> s;
    cout << mp[s] << endl;
  }

  return 0;
}