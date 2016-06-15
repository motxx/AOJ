#include <cstdlib>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int size = s.size();
    int res, ans = 0;
    bool f = true;
    set<int> set1;
    set1.insert(atoi(s.c_str()));
    while (size > 1) {
      res = 0;
      for (int i = 0; i < size - 1; i++) {
        string a = s.substr(0, i + 1);
        string b = s.substr(i + 1);
        res = max(atoi(a.c_str()) * atoi(b.c_str()), res);
      }
      if (set1.count(res)) {
        f = false;
        break;
      }
      set1.insert(res);
      stringstream ss;
      ss << res;
      s = ss.str();
      size = s.size();
      ans++;
    }
    cout << (f ? ans : -1) << endl;
  }

  return 0;
}