#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

struct data {
  int m1, d1, h, m;
  int time() const { return h * 60 + m; }
  bool operator<(data const& d) const {
    if (m1 != d.m1) return m1 < d.m1;
    if (d1 != d.d1) return d1 < d.d1;
    return h != d.h ? h < d.h : m < d.m;
  }
};

int main() {
  int N;
  while (cin >> N && N) {
    vector<data> v[1000];
    int m1, d1, h, m, u;
    char ch;
    rep(i, N) {
      scanf("%d/%d %d:%d %c %d", &m1, &d1, &h, &m, &ch, &u);
      v[u].push_back((data){m1, d1, h, m});
    }
    rep(i, 1000) {
      if (v[i].empty()) continue;
      sort(v[i].begin(), v[i].end());
    }

    int ans[1000] = {};
    REP(i, 1, 1000) {
      if (v[i].empty()) continue;
      rep(j, v[i].size() / 2) {
        data const &vi0 = v[i][2 * j], vi1 = v[i][2 * j + 1];
        rep(k, v[0].size() / 2) {
          if (v[0][2 * k].m1 != v[i][2 * j].m1 ||
              v[0][2 * k].d1 != v[i][2 * j].d1)
            continue;
          data const &v00 = v[0][2 * k], v01 = v[0][2 * k + 1];
          ans[i] +=
              max(0, min(v01.time(), vi1.time()) - max(v00.time(), vi0.time()));
        }
      }
    }
    int a = 0;
    rep(i, 1000) { a = max(a, ans[i]); }
    cout << a << endl;
  }
  return 0;
}