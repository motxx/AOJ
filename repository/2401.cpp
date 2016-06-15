#include <bits/stdc++.h>
int i, v;
std::string s;
int P() {
  i++;
  if (s[i] == 'T') return 1;
  if (s[i] == 'F') return 0;
  if (isalpha(s[i])) return v >> (s[i] - 'a') & 1;
  if (s[i] == '-') return !P();
  int l = P();
  i++;
  int o = s[i];
  if (o == '-') i++;
  int r = P();
  i++;
  if (o == '*') return l & r;
  if (o == '+') return l | r;
  if (o == '-') return l <= r;
}
int main() {
  while (std::cin >> s) {
    if (s == "#") break;
    int k = 1;
    for (v = 0; v < (1 << 11); v++) {
      i = -1;
      int l = P();
      i++;
      if (l != P()) {
        k = 0;
        break;
      }
    }
    std::cout << (k ? "YES\n" : "NO\n");
  }
  return 0;
}