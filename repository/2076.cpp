#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

const long long Inf = numeric_limits<long long>::max() / 4;

namespace flow_algorithm {
template <class Flow>
struct edge {
  int to;
  Flow cap, rev;
};
/*
  template<class Flow>
  using edges = vector<edge<Flow>>;

  template<class Flow>
  using graph = vector<edges<Flow>>;
*/

typedef vector<edge<long long>> edges;
typedef vector<edges> graph;

template <class Flow>
class dinic {
 private:
  int V;
  //    graph<Flow> g;
  graph g;
  vector<int> level;
  vector<int> iter;

 public:
  //    Flow static constexpr Inf = numeric_limits<Flow>::max() / 4;

 private:
  void bfs(int s) {
    rep(i, V) level[i] = -1;
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while (!q.empty()) {
      int curr = q.front();
      q.pop();
      rep(i, g[curr].size()) {
        edge<Flow>& e = g[curr][i];
        if (level[e.to] != -1) {
          continue;
        }
        if (e.cap <= 0) {
          continue;
        }
        level[e.to] = level[curr] + 1;
        q.push(e.to);
      }
    }
  }

  Flow dfs(int curr, int tar, Flow flow) {
    if (curr == tar) {
      return flow;
    }
    for (int& i = iter[curr]; i < (int)g[curr].size(); i++) {
      edge<Flow>& e = g[curr][i];
      if (e.cap <= 0) {
        continue;
      }
      if (level[curr] >= level[e.to]) {
        continue;
      }
      Flow d = dfs(e.to, tar, min(flow, e.cap));
      if (d <= 0) {
        continue;
      }
      e.cap -= d;
      g[e.to][e.rev].cap += d;
      return d;
    }
    return 0;
  }

 public:
  dinic(int V_) {
    V = V_;
    g.resize(V);
    level.resize(V);
    iter.resize(V);
  }

  void add_edge(int from, int to, Flow cap) {
    g[from].push_back({to, cap, (Flow)g[to].size()});
    g[to].push_back({from, 0, (Flow)g[from].size() - 1});
  }

  Flow max_flow(int src, int dest) {
    Flow flow = 0;
    for (;;) {
      bfs(src);
      if (level[dest] < 0) {
        return flow;
      }
      rep(i, V) iter[i] = 0;
      Flow f;
      while ((f = dfs(src, dest, Inf)) > 0) {
        flow += f;
      }
    }
  }
};
}

typedef long long ll;

int main() {
  int N;
  ll M, L;
  while (cin >> N >> M >> L) {
    ll g[N][N];
    rep(i, N) rep(j, N) g[i][j] = Inf;

    rep(i, M) {
      int a, b, d;
      cin >> a >> b >> d;
      a--, b--;
      g[a][b] = g[b][a] = d;
    }

    rep(k, N) rep(i, N) rep(j, N) {
      if (g[i][k] == Inf && g[k][j] == Inf) {
        continue;
      }
      g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    }

    rep(i, N) { g[i][i] = 0; }

    int const SRC = 2 * N + 1, SINK = 2 * N + 2;

    flow_algorithm::dinic<ll> dn(2 * N + 10);

    vector<int> ps(N);
    rep(i, N) {
      cin >> ps[i];
      dn.add_edge(SRC, i, ps[i]);
    }

    rep(i, N) rep(j, N) {
      //      if(i == j) { continue; }
      if (g[i][j] < L) {
        dn.add_edge(i, N + j, Inf);
      }
    }

    rep(i, N) {
      ll K;
      cin >> K;
      dn.add_edge(N + i, SINK, K);
    }

    cout << dn.max_flow(SRC, SINK) << endl;
  }

  return 0;
}