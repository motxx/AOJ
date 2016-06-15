#include <bits/stdc++.h>
using namespace std;

int main() {
  int M, N;
  while (cin >> M >> N && M) {
    vector<int> books(N);
    for (int i = 0; i < N; i++) {
      cin >> books[i];
    }

    int l = 1, r = 1500001;
    while (r - l > 1) {
      int m = (l + r) / 2;
      int BPS = 0;
      for (int i = 0; i < M; i++) {
        int size = m;
        for (;;) {
          if (BPS == N) break;
          if (size - books[BPS] < 0) break;
          size -= books[BPS++];
        }
        if (BPS == N) break;
      }
      if (BPS == N) {
        r = m;
      } else
        l = m;
    }

    cout << l + 1 << endl;
  }

  return 0;
}