#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long double Double;

int main() {
  typedef pair<int, int> Pii;
  typedef pair<int, Pii> Piii;

  int N;
  int const M = 256;
  while (cin >> N && N) {
    vector<int> I(N);
    rep(i, N) cin >> I[i];
    Double Entropy = 1e60;
    Piii ans;
    rep(S, 16) rep(A, 16) rep(C, 16) {
      int numofx[256] = {};
      int R = S;
      rep(i, N) {
        R = (A * R + C) % M;
        numofx[(I[i] + R) % M]++;
      }
      Double H = 0.;
      rep(i, M) {
        if (numofx[i]) {
          Double x = (Double)numofx[i] / N;
          H -= x * log(x);
        }
      }
      if (H < Entropy - 1e-9) {
        Entropy = H;
        ans = Piii(S, Pii(A, C));
      } else if (H == Entropy) {
        ans = min(ans, Piii(S, Pii(A, C)));
      }
    }
    cout << ans.first << " " << ans.second.first << " " << ans.second.second
         << endl;
  }

  return 0;
}