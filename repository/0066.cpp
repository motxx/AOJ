#include <iostream>
using namespace std;

string str;

bool isWin(char c) {
  for (int i = 0; i < 3; i++) {
    int cnt = 0;
    for (int j = 0; j < 3; j++) {
      if (str[i * 3 + j] == c) cnt++;
    }
    if (cnt == 3) return true;
  }

  for (int i = 0; i < 3; i++) {
    int cnt = 0;
    for (int j = 0; j < 3; j++) {
      if (str[j * 3 + i] == c) cnt++;
    }
    if (cnt == 3) return true;
  }

  if (str[0] == c && str[4] == c && str[8] == c) return true;

  if (str[2] == c && str[4] == c && str[6] == c) return true;

  return false;
}

int main() {
  while (cin >> str) {
    bool fO = isWin('o');
    bool fX = isWin('x');
    if (!fO && !fX)
      cout << "d" << endl;
    else
      cout << (fO ? "o" : "x") << endl;
  }
  return 0;
}