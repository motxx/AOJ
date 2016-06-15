#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;

  while (cin >> n && n) {
    map<int, ll> mp;
    vector<ll> v;

    for (int i = 0; i < n; i++) {
      int a;
      ll b, c;
      cin >> a >> b >> c;
      if (!mp[a]) v.push_back(a);
      mp[a] += b * c;
    }

    bool isExist = false;
    for (int i = 0; i < v.size(); i++) {
      if (mp[v[i]] >= 1000000) {
        isExist = true;
        cout << v[i] << endl;
      }
    }
    if (!isExist) cout << "NA" << endl;
  }

  return 0;
}