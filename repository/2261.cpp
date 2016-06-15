#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, char> sym;

void init() {
  sym['('] = ')';
  sym[')'] = '(';
  sym['['] = ']';
  sym[']'] = '[';
  sym['{'] = '}';
  sym['}'] = '{';
}

bool check(string s, string t) {
  int l = s.size();
  int r = t.size();
  if (l != r) return false;
  // cout << s+"iwi"+t << endl;
  for (int i = 0; i < l; i++) {
    if (sym[s[i]] != t[r - i - 1]) return false;
  }
  return true;
}

string makestr(string str, long long S) {
  string ret;
  int n = str.size();

  for (int i = 0; i < n; i++) {
    if (S >> i & 1) ret += str[i];
  }
  // cout << ret << endl;
  return ret;
}

int main() {
  init();

  string str;
  getline(cin, str);

  int pos = str.find("iwi");
  string strL = str.substr(0, pos);
  string strR = str.substr(pos + 3);
  int l = strL.size(), r = strR.size();

  int mx = 0;
  for (long long S = 0; S < (1 << l); S++) {
    for (long long T = 0; T < (1 << r); T++) {
      string s = makestr(strL, S);
      string t = makestr(strR, T);
      // cout << s+"iwi"+t << endl;
      if (check(s, t)) {
        mx = max(mx, (int)s.size() + (int)t.size() + 3);
      }
    }
  }

  cout << mx << endl;

  return 0;
}