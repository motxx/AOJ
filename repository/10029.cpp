#include <algorithm>
#include <iostream>
using namespace std;
main() {
  int s[1000000], n, i;
  cin >> n;
  for (i = 0; i < n; i++) cin >> s[i];
  sort(s, s + n);
  for (i = 0; i < n - 1; i++) cout << s[i] << " ";
  cout << s[n - 1] << '\n';
}