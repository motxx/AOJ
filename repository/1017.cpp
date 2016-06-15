#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, R;
  while (cin >> N >> R) {
    queue<int> A, B, C;
    rep(i, N) { C.push(i); }
    rep(_, R) {
      int c;
      cin >> c;
      rep(i, N) {
        if (N / 2 <= i) {
          A.push(C.front());
        } else {
          B.push(C.front());
        }
        C.pop();
      }

      for (; (!A.empty()) || (!B.empty());) {
        rep(i, c) {
          if (A.empty()) break;
          C.push(A.front());
          A.pop();
        }
        rep(i, c) {
          if (B.empty()) break;
          C.push(B.front());
          B.pop();
        }
      }
    }
    cout << C.back() << endl;
  }

  return 0;
}