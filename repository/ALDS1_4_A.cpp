#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  int Q;
  cin >> Q;
  vector<int> b(Q);
  for (int i = 0; i < Q; i++) cin >> b[i];
  vector<bool> c(Q);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < Q; j++) {
      if (a[i] == b[j] && !c[j]) c[j] = true, ans++;
    }
  }
  cout << ans << endl;
  return 0;
}