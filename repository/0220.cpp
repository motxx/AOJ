#include <bits/stdc++.h>

using namespace std;

// container utility
#define ALL(x) (x).begin(), (x).end()

// rep
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)

string func(int x) {
  string ret;
  while (x > 0) {
    ret += char(x % 2 + '0');
    x /= 2;
  }

  reverse(ALL(ret));
  return ret;
}

int main() {
  double in;

  while (cin >> in && in > 0.0) {
    string int_part = func(int(in));
    in *= 16;  // in <<= 4; (integer type only)
    if (ceil(in) != in) {
      cout << "NA" << endl;
    } else {
      rep(i, 8 - int_part.size()) cout << 0;
      cout << int_part << '.';
      string decimal_part = func(int(in));
      cout << decimal_part.substr(decimal_part.size() - 4) << endl;
    }
  }

  return 0;
}