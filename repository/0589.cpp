#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class grtr {
 public:
  bool operator()(const string &s, const string &t) {
    return s.size() != t.size() ? s.size() < t.size() : s < t;
  }
};

int main() {
  map<string, int, grtr> mp;
  int n;
  cin >> n;
  string s;
  int a;

  for (int i = 0; i < n; i++) {
    cin >> s >> a;
    mp[s] += a;
  }

  for (map<string, int, grtr>::iterator it = mp.begin(); it != mp.end(); it++)
    cout << it->first << " " << it->second << endl;

  return 0;
}