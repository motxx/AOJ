#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  while (N--) {
    int a[9], b[9];
    for (int i = 0; i < 9; i++) cin >> a[i];
    for (int i = 0; i < 9; i++) cin >> b[i];
    sort(a, a + 9);
    double A = 0, B = 0;
    do {
      int cntA = 0, cntB = 0;
      for (int i = 0; i < 9; i++) {
        if (a[i] < b[i])
          cntB += a[i] + b[i];
        else
          cntA += a[i] + b[i];
      }
      if (cntA < cntB)
        B++;
      else
        A++;
    } while (next_permutation(a, a + 9));
    cout << A / tgamma(10) << ' ' << B / tgamma(10) << endl;
  }

  return 0;
}