#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int a[N];  // sorted
  for (int i = 0; i < N; i++) scanf("%d", &a[i]);
  int Q;
  cin >> Q;
  int ans = 0;
  while (Q--) {
    int b;
    cin >> b;
    int l = 0, r = N;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (a[m] <= b) {
        l = m;
      } else {
        r = m;
      }
    }
    if (a[l] == b) ans++;  // lower_bound
  }

  printf("%d\n", ans);
  return 0;
}