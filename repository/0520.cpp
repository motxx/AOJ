#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

struct tree {
  ll p = -1, q = -1, r = -1, b = -1;
  tree() = default;
  tree(int p, int q, int r, int b) : p(p), q(q), r(r), b(b) {}
};

tree t[111];

ll dfs(int idx) {
  ll left = 0, right = 0;
  left = (t[idx].r ? dfs(t[idx].r - 1) : 1) * t[idx].p;
  right = (t[idx].b ? dfs(t[idx].b - 1) : 1) * t[idx].q;
  ll k = left * right / __gcd(left, right) / t[idx].p;
  ll l = left * right / __gcd(left, right) / t[idx].q;
  return k + l;
}

int main() {
  for (int N; cin >> N && N;) {
    rep(i, N) t[i] = tree(-1, -1, -1, -1);
    set<int> st;
    rep(i, N) {
      int p, q, r, b;
      cin >> p >> q >> r >> b;
      t[i] = {p, q, r, b};
      if (r > 0) st.insert(r - 1);
      if (b > 0) st.insert(b - 1);
    }
    rep(i, N) {
      if (!st.count(i)) {
        cout << dfs(i) << endl;
        break;
      }
    }
  }

  return 0;
}