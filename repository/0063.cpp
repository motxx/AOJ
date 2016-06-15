#include <iostream>
using namespace std;

int main() {
  string s;
  int res = 0;
  while (getline(cin, s)) {
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
      if (s[i] == s[n - i - 1]) cnt++;
    }
    if (cnt == n / 2) res++;
  }
  cout << res << endl;

  return 0;
}