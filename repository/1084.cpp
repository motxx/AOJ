#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, K;
  while (cin >> N >> K && (N | K)) {
    int C[N];
    rep(i, N) { cin >> C[i]; }

    int mx1 = 1;
    rep(i, N) {
      int mul = 1;
      REP(j, i, i + K) {
        if (j >= N) {
          mul = 0;
          break;
        }
        mul *= C[j];
      }
      mx1 = max(mx1, mul);
    }

    int ans = -1 << 29;
    rep(i, N) REP(j, i + 1, N) {
      swap(C[i], C[j]);
      rep(k, N) {
        int mul = 1;
        REP(l, k, k + K) {
          if (l >= N) {
            mul = -1 << 29;
            break;
          }
          mul *= C[l];
        }
        ans = max(ans, mul - mx1);
      }
      swap(C[i], C[j]);
    }

    if (ans < 0) {
      cout << "NO GAME\n";
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}