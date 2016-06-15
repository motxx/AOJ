#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

int x;

vi str2vi(string s) {
  vi ret(127);

  reverse(s.begin(), s.end());

  for (int i = 0; i < 126; i++) {
    if (i < s.size()) ret[i] = s[i] == 'X' ? x : s[i] - '0';
  }

  return ret;
}

vi pls(string s1, string s2) {
  vi ret(127);
  vi v1, v2;

  v1 = str2vi(s1), v2 = str2vi(s2);

  for (int i = 0; i < 126; i++) {
    ret[i] += v1[i] + v2[i];

    while (ret[i] > 9) {
      ret[i + 1]++;
      ret[i] -= 10;
    }
  }
  return ret;
}

bool check(string s) { return !(s.size() > 1 && s[0] == 'X'); }

int main() {
  string str;
  string s1, s2, rhs;
  while (cin >> str) {
    int ppos = str.find("+");
    int epos = str.find("=");
    rhs = str.substr(epos + 1);
    s1 = str.substr(0, ppos);
    s2 = str.substr(ppos + 1, epos - ppos - 1);

    // cout << s1 << " " << s2 << " " << rhs << endl;

    int ans = -1;
    for (x = 0; x < 10; x++) {
      if ((x || (check(s1) && check(s2) && check(rhs))) &&
          pls(s1, s2) == str2vi(rhs)) {
        ans = x;
        break;
      }
    }

    if (ans == -1)
      cout << "NA";
    else
      cout << ans;
    cout << endl;
  }

  return 0;
}