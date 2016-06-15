#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int p[8];

  while (1) {
    int c[8] = {4, 1, 4, 1, 2, 1, 2, 1};
    bool end = 0;
    for (int i = 0; i < 8; i++) {
      cin >> p[i];
      if (cin.eof()) {
        end = 1;
        break;
      }
    }
    if (end) break;

    int mn = (int)1e9;
    string ans;

    for (int I = 0; I < 8; I++) {
      int pep = 0;
      for (int i = 0; i < 8; i++) {
        pep += max(c[i] - p[i], 0);
      }

      if (mn > pep) {
        mn = pep;
        string s;
        for (int i = 0; i < 8; i++) {
          if (i) s += ' ';
          s += char('0' + c[i]);
        }
        ans = s;
      } else if (mn == pep) {
        string s;
        for (int i = 0; i < 8; i++) {
          if (i) s += ' ';
          s += char('0' + c[i]);
        }
        ans = min(ans, s);
      }

      rotate(c, c + 1, c + 8);
      /*
      for(int i=0; i<8; i++) {
        if(i) cout << ' ';
        cout << c[i];
      }
      cout << endl;
      */
    }  // for I

    cout << ans << endl;
  }

  return 0;
}