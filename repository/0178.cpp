#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

#define chmax(a, x) a = max(a, x)

vector<bool> F[5];

bool eraser(int idx) {
  rep(i, 5) {
    if ((int)F[i].size() <= idx) {
      return false;
    }
    if (!F[i][idx]) {
      return false;
    }
  }

  rep(i, 5) F[i].erase(F[i].begin() + idx);

  rep(i, 5) {
    while (1) {
      if (!F[i].empty() && !F[i].back()) {
        F[i].pop_back();
      } else {
        break;
      }
    }
  }

  return true;
}

int main() {
  for (int N; cin >> N && N;) {
    rep(i, 5) F[i].clear();
    rep(i, N) {
      int type, len, pos;
      cin >> type >> len >> pos;
      pos--;
      if (type == 1) {
        int mx = -1;
        REP(i, pos, pos + len) { chmax(mx, int(F[i].size())); }
        REP(i, pos, pos + len) {
          REP(j, F[i].size(), mx) { F[i].push_back(false); }
          F[i].push_back(true);
        }
        eraser(mx);
      } else {
        rep(i, len) { F[pos].push_back(true); }
        int cnt = 0;
        rep(i, len) {
          if (!eraser((int)F[pos].size() - 1 - cnt)) cnt++;
        }
      }
    }
    int sum = 0;
    rep(i, 5) rep(j, F[i].size()) sum += F[i][j];
    cout << sum << endl;
  }
  return 0;
}