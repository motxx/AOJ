#include <iostream>
using namespace std;

int main() {
  const int dx[] = {-1, 1, 0, 0};
  const int dy[] = {0, 0, -1, 1};
  string s;
  while (cin >> s) {
    for (unsigned i = 1; i < s.size(); i++) {
      int a = (s[i - 1] - 'A') / 3, b = (s[i] - 'A') / 3;
      int c = (s[i - 1] - 'A') % 3, d = (s[i] - 'A') % 3;
      bool ok = false;
      for (int k = 0; k < 4; k++) {
        if (a + dy[k] == b && c + dx[k] == d) ok = true;
      }
      if (!ok) goto fin;
    }
    cout << s + '\n';
  fin:;
  }
  return 0;
}