#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, double> mp;
  int st;
  char c;
  double w, h;

  while (cin >> st >> c >> w >> c >> h) {
    mp[st] = w / (h * h);
  }

  for (map<int, double>::iterator it = mp.begin(); it != mp.end(); it++) {
    if ((*it).second >= 25.0) cout << (*it).first << endl;
  }

  return 0;
}