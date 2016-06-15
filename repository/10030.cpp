#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, q;

  cin >> n;
  int s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  cin >> q;
  int t[q];
  for (int i = 0; i < q; i++) cin >> t[i];

  sort(s, s + n);
  sort(t, t + q);

  int i = 0, j = 0, cnt = 0;
  while (i < n && j < q) {
    if (s[i] == t[j]) ++cnt;

    if (s[i] < t[j])
      ++i;
    else
      ++j;
  }

  cout << cnt << endl;

  return 0;
}