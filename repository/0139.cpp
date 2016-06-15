#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int Tc;
  string s;
  while (cin >> Tc) {
    while (Tc--) {
      cin >> s;
      int const N = s.size();
      bool NA = 0;
      bool isA;
      if (s[0] != '>') NA = 1;
      if (s[1] == '\'') {
        if (s[2] != '=') NA = 1;
        for (int i = 2; i < (N - 3) / 2 + 2; i++)
          if (s[i] != '=') NA = 1;
        if (s.substr(2, (N - 3) / 2) + "~" != s.substr(3 + (N - 3) / 2)) NA = 1;
        if (s[(N - 3) / 2 + 2] != '#') NA = 1;
        isA = 1;
      } else if (s[1] == '^') {
        int cnt;
        if (!(s[2] == 'Q' && s[3] == '=')) NA = 1;
        for (cnt = 2; cnt < N - 2; cnt += 2) {
          if (!(s[cnt] == 'Q' && s[cnt + 1] == '=')) NA = 1;
        }
        if (!(s[cnt] == '~' && s[cnt + 1] == '~')) NA = 1;
        if (cnt + 2 != N) NA = 1;
        isA = 0;
      } else {
        NA = 1;
      }

      if (NA)
        cout << "NA" << endl;
      else if (isA)
        cout << "A" << endl;
      else
        cout << "B" << endl;
    }
  }

  return 0;
}