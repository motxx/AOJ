#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  const int A = 0, X = 1, Y = 2, Z = 3, W = 4, B = 5;

  string s;
  while (cin >> s) {
    if (s == "#") break;
    int now = A;
    int const size = s.size();
    bool over = false;
    for (int i = 0; i < size; i++) {
      switch (now) {
        case A:
          if (s[i] == '0')
            now = X;
          else
            now = Y;
          break;
        case X:
          if (s[i] == '1')
            now = Z;
          else {
            over = true;
            goto EXIT;
          }
          break;
        case Y:
          if (s[i] == '0')
            now = X;
          else {
            over = true;
            goto EXIT;
          }
          break;
        case Z:
          if (s[i] == '1')
            now = B;
          else
            now = W;
          break;
        case W:
          if (s[i] == '1')
            now = Y;
          else
            now = B;
          break;
        case B:
          if (s[i] == '1')
            now = X;
          else
            now = Y;
          break;
      }
    }
  EXIT:;
    if (over || now != B) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}