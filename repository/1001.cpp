#include <bits/stdc++.h>

using namespace std;

// rep
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)

void division(string const &raw, string &left, string &right) {
  int const N = raw.size();
  int retain = 0;
  REP(pos, 1, N) {
    if (raw[pos] == '(')
      retain++;
    else if (raw[pos] == ')')
      retain--;
    else if (retain == 0) {
      // assert(raw[pos] == ',');
      left = raw.substr(1, pos - 1);
      right = raw.substr(pos + 1, N - pos - 2);
      break;
    }
  }
}

string solve(char op, string const &s, string const &t) {
  if (s.empty() || t.empty()) {
    if (op == 'i')
      return min(s, t);
    else
      return max(s, t);
  }

  string sL, sR, tL, tR;
  division(s, sL, sR);
  division(t, tL, tR);

  return '(' + solve(op, sL, tL) + ',' + solve(op, sR, tR) + ')';
}

int main() {
  char op;
  string s, t;
  while (cin >> op >> s >> t) {
    cout << solve(op, s, t) << endl;
  }

  return 0;
}