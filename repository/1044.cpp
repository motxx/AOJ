#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string str;
  char op;
  while (cin >> str >> op) {
    if (op == 'X') break;
    for (int i = 0; i < (int)str.size(); i++) {
      if (str[i] == '_') {
        str[i] = ' ';
      } else if (isupper(str[i])) {
        char ch = tolower(str[i]);
        str = str.substr(0, i) + " " + ch + str.substr(i + 1);
      } else {
        str[i] = tolower(str[i]);
      }
    }
    stringstream ss(str);
    string ans;
    bool fsted = 0;
    while (ss >> str) {
      if (op == 'L') {
        if (fsted) {
          ans += toupper(str[0]);
          ans += str.substr(1);
        } else
          ans += str;
        fsted = 1;
      }
      if (op == 'U') {
        ans += toupper(str[0]);
        ans += str.substr(1);
      }
      if (op == 'D') {
        if (fsted) ans += '_';
        ans += str;
        fsted = 1;
      }
    }
    cout << ans << endl;
  }

  return 0;
}