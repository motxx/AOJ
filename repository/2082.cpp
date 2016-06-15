#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N, M;
  while (cin >> N >> M && (N || M)) {
    vector<int> L(N);
    rep(i, N) cin >> L[i];
    bool ok = 0;
    rep(m, 1 << M) {
      if (__builtin_popcount(m) != L[0]) continue;
      string temp;
      int count = L[0];
      rep(k, M) temp.push_back('0' + (m >> k & 1));
      bool ng = 0;
      REP(k, 1, N) {
        count -= temp[k - 1] == '1';
        if (L[k] == count)
          temp.push_back('0');
        else if (L[k] == count + 1)
          temp.push_back('1'), count++;
        else {
          ng = 1;
          break;
        }
      }
      if (ng) continue;
      cout << temp << endl;
      ok = 1;
      break;
    }
    if (!ok) cout << "Goofy" << endl;
  }

  return 0;
}