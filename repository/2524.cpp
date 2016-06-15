#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int toInt(string s) { return atoi(s.c_str()); }

bool solve(string s, string t) {
  if (s[0] == '0') return 0;
  if (t[0] == '0') return 0;

  int a = toInt(s);
  int b = toInt(t);

  if (a > b) return 0;
  if ((a + b) % 2) return 0;

  return 1;
}

int main() {
  string a;
  cin >> a;

  int const N = a.size();
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += solve(a.substr(0, i), a.substr(i));
  }

  cout << ans << endl;

  return 0;
}