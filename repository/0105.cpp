#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  string str;
  int t;
  map<string, vector<int>, less<string> > mp;

  for (; cin >> str >> t; mp[str].push_back(t))
    ;

  for (map<string, vector<int> >::iterator it = mp.begin(); it != mp.end();
       it++) {
    cout << (*it).first << endl;
    sort((*it).second.begin(), (*it).second.end());
    for (int i = 0; i < (*it).second.size() - 1; i++) {
      cout << (*it).second[i] << " ";
    }
    cout << (*it).second[(*it).second.size() - 1] << endl;
  }

  return 0;
}