#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)

#define rep(i, n) REP(i, 0, n)

int main() {
  string s;
  while (cin >> s) {
    if (s == "#") break;
    reverse(s.begin(), s.end());

    int a = 0;
    int n = 0;
    rep(i, s.size()) {
      if (s[i] == 'n') {
        a *= 2;
        if (n) {
          a -= 90;
        }
        if (n) {
          n <<= 1;
        } else {
          n = 1;
        }
        //   cerr << "north " << a << "/" << n << endl;
      }
      if (s[i] == 'w') {
        a *= 2;
        a += 90;
        if (n) {
          n <<= 1;
        } else {
          n = 1;
        }
        //    cerr << "west " << a << "/" << n << endl;
      }
    }

    int g = __gcd(a, n);
    if (g == 0) {
      cout << 0 << endl;
    } else {
      cout << a / g;
      if (n / g > 1) {
        cout << "/" << n / g;
      }
      cout << endl;
    }
  }

  return 0;
}