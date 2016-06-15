#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

struct state {
  int t, s, d;
};
bool cmp(state const& lhs, state const& rhs) { return lhs.t < rhs.t; }

int main() {
  int N, M;
  while (cin >> N >> M && (N | M)) {
    vector<state> v;
    rep(i, M) {
      int t, s, d;
      cin >> t >> s >> d;
      s--, d--;
      v.push_back((state){t, s, d});
    }
    sort(v.begin(), v.end(), cmp);
    vector<bool> g(N);
    g[0] = 1;
    rep(i, M) { g[v[i].d] = g[v[i].d] || g[v[i].s]; }
    int ans = 0;
    rep(i, N) {
      if (g[i]) {
        ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}