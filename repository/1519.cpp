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

ll w[100001];
ll d[100001];

struct union_find {
  vector<int> rid_;

  union_find(int n) { rid_.assign(n, -1); }

  void operator()(int u, int v, int c) {
    int nu = operator[](u), nv = operator[](v);
    if (nu == nv) return;
    rid_[nu] = nv;
    d[nu] = c - d[u] + d[v];
  }

  int operator[](int x) {
    if (rid_[x] < 0) {
      return x;
    } else {
      int p = rid_[x];
      rid_[x] = operator[](p);
      d[x] += d[p];
      return rid_[x];
    }
  }
};

int main() {
  int N, Q;
  cin >> N >> Q;
  union_find uf(N);

  rep(_, Q) {
    string query;
    cin >> query;
    if (query[0] == 'I') {
      ll a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      uf(a, b, c + w[a] - w[b]);
      w[a] += c;
      w[b] += c;
    } else {
      ll a, b;
      cin >> a >> b;
      a--, b--;
      if (uf[a] == uf[b])
        cout << -d[b] + d[a] + w[b] - w[a] << endl;
      else
        cout << "WARNING" << endl;
    }
  }

  return 0;
}