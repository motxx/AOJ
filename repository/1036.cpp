#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  string red, green, down_str;
  while (cin >> red >> green >> down_str) {
    if (cin.eof()) break;
    int rsize = red.size();
    int gsize = green.size();
    int dsize = down_str.size();

    string ans;
    int rpos = 0, gpos = 0;
    char cent = green[gpos++];
    for (int dpos = 0; rpos < rsize || gpos < gsize;) {
      if (dpos < dsize && down_str[dpos] == cent) {
        dpos++;
        cent = red[rpos++];
      } else {
        ans += cent;
        cent = green[gpos++];
      }
    }
    cout << ans + cent << endl;
  }

  return 0;
}