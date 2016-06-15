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

namespace flow {

class bipartite_matching {
 private:
  int V;
  vector<vector<int>> G;
  vector<int> match;
  vector<bool> used;

  bool dfs(int v) {
    used[v] = 1;
    for (auto &u : G[v]) {
      int w = match[u];
      if (w < 0 || (!used[w] && dfs(w))) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }

 public:
  bipartite_matching(int V) : V(V) {
    G.resize(V), match.resize(V), used.resize(V);
  }

  void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int maximum_matching() {
    int ret = 0;
    match.clear(), match.resize(V, -1);
    rep(v, V) {
      if (match[v] < 0) {
        used.clear(), used.resize(V, 0);
        if (dfs(v)) {
          ret++;
        }
      }
    }
    return ret;
  }
};
}

int main() {
  int N, M, L;
  while (cin >> N >> M >> L && (N | M | L)) {
    int D[N][N];
    rep(i, N) rep(j, N) D[i][j] = inf;
    rep(i, N) D[i][i] = 0;
    rep(i, M) {
      int u, v, d;
      cin >> u >> v >> d;
      minimize(D[u][v], d);
      minimize(D[v][u], d);
    }

    int P[L], T[L];
    rep(i, L) { cin >> P[i] >> T[i]; }

    rep(k, N) rep(i, N) rep(j, N) { minimize(D[i][j], D[i][k] + D[k][j]); }

    flow::bipartite_matching bp(2 * L);

    rep(i, L) rep(j, L) {
      if (i == j) continue;
      if (D[P[i]][P[j]] <= T[j] - T[i]) {
        bp.add_edge(i, L + j);
      }
    }

    cout << L - bp.maximum_matching() << endl;
  }

  return 0;
}