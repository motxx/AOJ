#include <iostream>
using namespace std;

void divStr(const string& s, string& s1, string& s2) {
  int n = s.size();
  int retain = 0;
  for (int pos = 1;; pos++) {
    if (s[pos] == '(') retain++;
    if (s[pos] == ')')
      retain--;
    else if (retain == 0) {
      s1 = s.substr(1, pos - 1);
      s2 = s.substr(pos + 1, n - pos - 2);
      return;
    }
  }
}

string make(string op, string s, string t) {
  if (s == "" || t == "") {
    if (op == "i")
      return "";
    else
      return s == "" ? t : s;
  }

  string sL, sR, tL, tR;
  divStr(s, sL, sR);
  divStr(t, tL, tR);

  return '(' + make(op, sL, tL) + ',' + make(op, sR, tR) + ')';
}

int main() {
  string op, sL, sR;

  while (cin >> op >> sL >> sR) cout << make(op, sL, sR) << endl;

  return 0;
}