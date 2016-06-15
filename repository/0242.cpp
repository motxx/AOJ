#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  int N;
  while (cin >> N && N) {
    cin.ignore();
    stringstream ss;
    for (int i = 0; i < N; i++) {
      string s;
      getline(cin, s);
      s += ' ';
      ss << s;
    }
    string s;
    vector<string> vec;
    while (ss >> s) {
      vec.push_back(s);
    }
    sort(vec.begin(), vec.end());
    map<string, int> mp;
    int cnt = 1;
    for (int i = 0; i < vec.size(); i++) {
      // cout << vec[i] << endl;
      if (i < vec.size() - 1 && vec[i] == vec[i + 1]) {
        cnt++;
      } else {
        mp[vec[i]] = cnt;
        cnt = 1;
      }
    }
    // cout << endl;
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    string q;
    cin >> q;
    vector<pair<int, string> > vec2;
    for (int i = 0; i < vec.size(); i++) {
      if (vec[i][0] == q[0]) {
        vec2.push_back(make_pair(-mp[vec[i]], vec[i]));
        // cout <<vec[i] << " " << mp[vec[i]] << endl;
      }
    }
    sort(vec2.begin(), vec2.end());
    int ok = 0;
    for (int i = 0; i < vec2.size(); i++) {
      if (vec2[i].second[0] == q[0]) {
        ok++;
        if (ok == 6) break;
        if (i) cout << " ";
        cout << vec2[i].second;
      }
    }
    if (!ok) cout << "NA";
    cout << endl;
  }
  return 0;
}