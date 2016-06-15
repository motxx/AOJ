#include <iostream>

using namespace std;
string so[10] = {"* = ****", "* =* ***", "* =** **", "* =*** *", "* =**** ",
                 " *= ****", " *=* ***", " *=** **", " *=*** *", " *=**** "};

int main() {
  string s;
  char start[8][6] = {"*****", "     ", "=====", "     ",
                      "*****", "*****", "*****", "*****"};

  char grid[8][6];
  bool blink = 0;
  while (cin >> s) {
    if (blink) cout << endl;
    blink = 1;
    for (int i = 0; i < 8; i++)
      for (int j = 0; j < 6; j++) grid[i][j] = start[i][j];

    int const size = s.size();
    int const OFFSET = 5 - s.size();

    for (int j = 0; j < 5 - OFFSET; j++)
      for (int i = 0; i < 8; i++)
        grid[i][j + OFFSET] = so[(int)(s[j] - '0')][i];

    for (int i = 0; i < 8; i++) {
      cout << grid[i] << endl;
    }
  }

  return 0;
}