#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  for (int a, L; cin >> a >> L, (a | L);) {
    map<int, int> mp;
    for (int i = 0;; i++) {
      if (mp.count(a)) {
        cout << mp[a] << ' ' << a << ' ' << i - mp[a] << endl;
        break;
      }

      mp[a] = i;
      stringstream ss;
      ss << a;
      string s = ss.str();
      int N = s.size();
      vector<int> vec;
      for (int i = 0; i < L; i++) {
        if (i < N)
          vec.push_back(s[i] - '0');
        else
          vec.push_back(0);
      }

      sort(vec.begin(), vec.end());
      N = vec.size();
      int small = 0;
      for (int i = 0; i < N; i++) {
        small *= 10;
        small += vec[i];
      }
      int big = 0;
      for (int i = N - 1; i >= 0; i--) {
        big *= 10;
        big += vec[i];
      }
      a = big - small;
    }
  }

  return 0;
}