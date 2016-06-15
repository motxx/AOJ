#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, L;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> L;
    N = __gcd(L, N);
  }

  if (N == 1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}