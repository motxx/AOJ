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

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
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

namespace tree {
namespace diameter {

using Weight = ll;
using Edge = pair<int, Weight>;
using Graph = vector<vector<Edge>>;

namespace detail {
using Result = pair<Weight, int>;

Result visit(int parent, int curr, Graph const& G) {
  Result ret(0, curr);
  for (auto&& e : G[curr]) {
    int to;
    Weight weight;
    tie(to, weight) = e;
    if (to == parent) {
      continue;
    }
    auto t = visit(curr, to, G);
    t.first += weight;
    if (ret.first < t.first) {
      ret = t;
    }
  }
  return ret;
}
}

using Result = tuple<Weight, int, int>;

Result diameter(Graph const& G) {
  auto r = detail::visit(-1, 0, G);
  auto t = detail::visit(-1, r.second, G);
  return Result{t.first, r.second, t.second};
}

#define USE_TREE_DIAMETER       \
  using tree::diameter::Weight; \
  using tree::diameter::Edge;   \
  using tree::diameter::Graph;  \
  using tree::diameter::diameter;
}
}

USE_TREE_DIAMETER

int main() {
  int N;
  cin >> N;
  Graph g(N);
  rep(i, N - 1) {
    int s, t, w;
    cin >> s >> t >> w;
    g[s].emplace_back(t, w);
    g[t].emplace_back(s, w);
  }

  Weight w;
  int _;
  tie(w, _, _) = diameter(g);
  cout << w << endl;

  return 0;
}