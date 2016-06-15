#include <bits/stdc++.h>
using namespace std;
int main() {
  for (string s; cin >> s;) {
    int const sz = s.size();
    int joi = 0;
    {
      vector<int> jpos;
      for (int i = 0; i < sz; i++) {
        if (s[i] == 'J') jpos.push_back(i);
      }
      for (int i = 0; i < jpos.size(); i++) {
        if ((jpos[i] + 2 < sz) && (s[jpos[i] + 1] == 'O') &&
            (s[jpos[i] + 2] == 'I'))
          joi++;
      }
    }
    int ioi = 0;
    {
      vector<int> ipos;
      for (int i = 0; i < sz; i++) {
        if (s[i] == 'I') ipos.push_back(i);
      }
      for (int i = 0; i < ipos.size(); i++) {
        if ((ipos[i] + 2 < sz) && (s[ipos[i] + 1] == 'O') &&
            (s[ipos[i] + 2] == 'I'))
          ioi++;
      }
    }
    cout << joi << endl << ioi << endl;
  }
  return 0;
}