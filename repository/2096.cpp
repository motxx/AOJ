#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

constexpr long long Inf = numeric_limits<long long>::max() / 4;

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

int const SBASE = 10;
int const SRC = 150, SINK = 151;

int main() {
  map<string, int> mp = {{"Monday", 0},   {"Tuesday", 1}, {"Wednesday", 2},
                         {"Thursday", 3}, {"Friday", 4},  {"Saturday", 5},
                         {"Sunday", 6}};

  int N;
  ll W;
  while (cin >> N >> W && (N | W)) {
    flow_algorithm::dinic<ll> dn(200);

    rep(i, 7) dn.add_edge(SRC, i, W);

    ll need = 0;

    rep(i, N) {
      ll t;
      int c;
      cin >> t >> c;
      need += t;
      rep(j, c) {
        string s;
        cin >> s;
        //        dn.add_edge(mp[s], SBASE+i, flow_algorithm::dinic<ll>::Inf);
        dn.add_edge(mp[s], SBASE + i, Inf);
      }
      dn.add_edge(SBASE + i, SINK, t);
    }

    cout << (dn.max_flow(SRC, SINK) == need ? "Yes" : "No") << endl;
  }

  return 0;
}