#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, m;

  cin >> n >> m;
  int A[1000], B[1000];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int cnt[1000] = {};

  for (int i = 0; i < m; i++) {
    cin >> B[i];
  }

  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (B[j] >= A[i]) {
        cnt[i]++;
        break;
      }
    }
  }

  int mx = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (mx < cnt[i]) {
      num = i;
      mx = cnt[i];
    }
  }

  cout << num + 1 << endl;

  return 0;
}