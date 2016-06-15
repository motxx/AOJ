#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, M, Q;
  while (cin >> N >> M >> Q && (N | M | Q)) {
    int S[36][1000];
    string prev;
    rep(i, M) prev += '0';
    rep(i, 36) { rep(j, 1000) S[i][j] = 1; }

    rep(I, Q) {
      string s, t;
      cin >> s >> t;
      rep(i, N) rep(j, M) {
        if (bool(s[i] - '0') == (t[j] - '0' == prev[j] - '0')) {
          S[i][j] = 0;
        }
      }
      prev = t;
    }

    rep(j, M) {
      int id = -1;
      rep(i, N) {
        if (id != -1 && S[i][j]) {
          id = -1;
          break;
        }
        if (id == -1 && S[i][j]) {
          id = i;
        }
      }
      if (id == -1) {
        cout << '?';
      } else {
        cout << (id < 10 ? char('0' + id) : char('A' + (id - 10)));
      }
    }
    cout << endl;
  }

  return 0;
}