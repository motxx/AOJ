#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  int n;

  while (cin >> n && n) {
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
      int const N = s.size();
      int cnt = 1;
      string ns;
      for (int j = 0; j < N; j++) {
        if (j < N - 1 && s[j] == s[j + 1])
          cnt++;
        else {
          stringstream ss;
          ss << cnt;
          ns += ss.str();
          ns += s[j];
          cnt = 1;
        }
      }
      s = ns;
    }

    cout << s << endl;
  }

  return 0;
}