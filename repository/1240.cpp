#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

string revJ(string s) { return s[s.size() - 1] + s.substr(0, s.size() - 1); }

string revC(string s) { return s.substr(1) + s[0]; }

string revE(string s) {
  int n = s.size();
  string ret = s.substr(n - n / 2);
  if (n % 2) ret += s[n / 2];
  ret += s.substr(0, n / 2);
  return ret;
}

string revA(string s) {
  reverse(s.begin(), s.end());
  return s;
}

string revP(string s) {
  for (int i = 0; i < s.size(); i++)
    if (isdigit(s[i])) s[i] = static_cast<char>(((s[i] - '0') + 9) % 10 + '0');
  return s;
}

string revM(string s) {
  for (int i = 0; i < s.size(); i++)
    if (isdigit(s[i])) s[i] = static_cast<char>(((s[i] - '0') + 11) % 10 + '0');
  return s;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    string cmd, s;
    cin >> cmd >> s;
    reverse(cmd.begin(), cmd.end());
    int Ncmd = cmd.size();
    for (int i = 0; i < Ncmd; i++) {
      switch (cmd[i]) {
        case 'A':
          s = revA(s);
          break;
        case 'C':
          s = revC(s);
          break;
        case 'E':
          s = revE(s);
          break;
        case 'J':
          s = revJ(s);
          break;
        case 'M':
          s = revM(s);
          break;
        case 'P':
          s = revP(s);
          break;
      }
    }
    cout << s << endl;
  }

  return 0;
}