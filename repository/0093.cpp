#include <iostream>
#include <map>
using namespace std;

int main() {
  int a, b;
  bool stF = false;

  while (cin >> a >> b && (a | b)) {
    if (stF) cout << endl;
    stF = true;
    map<int, bool> mp;
    for (int i = a; i <= b; i++) {
      if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) mp[i] = true;
    }

    if (mp.size()) {
      for (map<int, bool>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << endl;
      }
    } else {
      cout << "NA" << endl;
    }
  }

  return 0;
}