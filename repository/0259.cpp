#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  string str;
  while (cin >> str) {
    if (str == "0000") break;
    int const size = str.size();

    bool ok = true;
    for (int i = 0; i < size - 1; i++) {
      ok = ok && str[i] == str[i + 1];
    }
    if (ok) {
      cout << "NA" << endl;
      continue;
    }

    int cnt = 0;
    while (1) {
      if (str == "6174") {
        break;
      }
      string L = str, S = str;
      sort(S.begin(), S.end());
      sort(L.begin(), L.end(), greater<char>());
      const char *pL = L.c_str();
      const char *pS = S.c_str();
      char *e;
      int l = strtol(pL, &e, 10);
      int s = strtol(pS, &e, 10);
      int n = l - s;
      for (int i = 0; i < size; i++) {
        str[size - i - 1] = char(n % 10 + '0');
        n /= 10;
      }
      cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}