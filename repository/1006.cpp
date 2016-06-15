#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < int(b); i++)
#define rep(i, n) REP(i, 0, n)

int to_minutes(int x) { return x / 100 * 60 + x % 100; }

int main() {
  int N, P, Q;
  while (cin >> N >> P >> Q && (N | P | Q)) {
    P = to_minutes(P), Q = to_minutes(Q);
    Q -= P;
    int TL[Q + 1];
    memset(TL, 0, sizeof TL);
    rep(_, N) {
      int K;
      cin >> K;
      rep(__, K) {
        int a, b;
        cin >> a >> b;
        a = to_minutes(a), b = to_minutes(b);
        a -= P, b -= P;
        REP(i, a, b) { TL[i]++; }
      }
    }
    /*
    rep(i, Q) {
      cout << TL[i] << " ";
    }
    cout << endl;
    */
    int counter = 0;
    int ans = 0;
    rep(i, Q) {
      if (TL[i] == N) {
        ans = max(ans, counter);
        counter = 0;
      } else {
        counter++;
        ans = max(ans, counter);
      }
    }
    cout << ans << endl;
  }

  return 0;
}