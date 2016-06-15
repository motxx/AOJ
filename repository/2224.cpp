#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
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

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

struct union_find {
  vector<int> rank_, size_, rid_;
  union_find(int n) {
    rank_.resize(n);
    rid_.assign(n, -1);
    size_.resize(n, 1);
  }
  void operator()(int u, int v) {
    u = operator[](u), v = operator[](v);
    if (u == v) {
      return;
    }
    size_[u] = size_[v] = size_[u] + size_[v];
    if (rank_[u] < rank_[v]) {
      rid_[u] = v;
    } else {
      rid_[v] = u;
      if (rank_[u] == rank_[v]) {
        rank_[u]++;
      }
    }
  }
  int operator[](int x) {
    if (rid_[x] < 0)
      return x;
    else
      return rid_[x] = operator[](rid_[x]);
  }
  int size_of(int x) { return size_[x]; }
};

using edge = tuple<int, int, double>;
vector<edge> edges;

int main() {
  int N, M;
  cin >> N >> M;
  vector<complex<double>> pts;
  rep(i, N) {
    double x, y;
    cin >> x >> y;
    pts.emplace_back(x, y);
  }
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    edges.emplace_back(x, y, abs(pts[x] - pts[y]));
  }

  union_find uf(N);

  sort(all(edges),
       [&](const edge& a, const edge& b) { return get<2>(a) > get<2>(b); });

  double cost = 0.0;

  rep(i, M) {
    int x, y;
    double c;
    tie(x, y, c) = edges[i];
    if (uf[x] == uf[y])
      cost += c;
    else
      uf(x, y);
  }

  printf("%.10f\n", cost);

  return 0;
}