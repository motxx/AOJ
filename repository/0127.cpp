#include <iostream>

using namespace std;

int main() {
  string s;
  while (cin >> s) {
    int const N = s.size();
    string ans;
    bool ok = 1;

    if (N % 2) ok = 0;

    for (int i = 1; i < N; i += 2) {
      int a = s[i - 1] - '0', b = s[i] - '0';

      if (a < 1 || 6 < a || b < 1 || 5 < b) ok = 0;
      char ch = (a - 1) * 5 + (b - 1) + 'a';
      if (!isalpha(ch)) {
        if (a == 6 && b == 2)
          ch = '.';
        else if (a == 6 && b == 3)
          ch = '?';
        else if (a == 6 && b == 4)
          ch = '!';
        else if (a == 6 && b == 5)
          ch = ' ';
        else
          ok = 0;
      }
      if (ok)
        ans += ch;
      else
        break;
    }

    if (ok) {
      cout << ans << endl;
    } else {
      cout << "NA" << endl;
    }
  }

  return 0;
}