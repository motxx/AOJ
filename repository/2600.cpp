#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int N, W, H;
int sumx[100010];
int sumy[100010];

int main() {
  cin >> N >> W >> H;
  rep(i, N) {
    int x, y, w;
    cin >> x >> y >> w;
    sumx[max(0, x - w)]++, sumx[min(W + 1, x + w)]--;
    sumy[max(0, y - w)]++, sumy[min(H + 1, y + w)]--;
  }
  REP(i, 1, 100010) {
    sumx[i] += sumx[i - 1];
    sumy[i] += sumy[i - 1];
  }

  bool ok = true;
  rep(i, W) {
    if (sumx[i] == 0) ok = false;
  }
  if (!ok) {
    ok = true;
    rep(i, H) {
      if (sumy[i] == 0) ok = false;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}