#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  while (cin >> N >> M && (N | M)) {
    vector<int> vec(N + M);
    for (int i = 0; i < N + M; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    int mx = 0, prev = 0;
    for (int i = 0; i < N + M; i++) {
      mx = max(mx, vec[i] - prev);
      prev = vec[i];
    }
    cout << mx << endl;
  }

  return 0;
}