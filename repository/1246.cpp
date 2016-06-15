#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int const INF = 1e9;
struct edge {
  int to, cap, cost, rev;
};

int const V = 366;
typedef pair<int, int> Pii;

vector<edge> G[V];
int h[V], dist[V];
int prevv[V], preve[V];

inline void add_edge(int from, int to, int cap, int cost) {
  G[from].push_back((edge){to, cap, -cost, (int)G[to].size()});
  G[to].push_back((edge){from, 0, cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f) {
  int res = 0;
  memset(h, 0, sizeof h);

  while (f > 0) {
    priority_queue<Pii, vector<Pii>, greater<Pii> > pq;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    pq.push(Pii(0, s));
    while (!pq.empty()) {
      Pii p = pq.top();
      pq.pop();
      int v = p.second;

      if (dist[v] < p.first) {
        continue;
      }

      rep(i, G[v].size()) {
        edge &e = G[v][i];
        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          pq.push(Pii(dist[e.to], e.to));
        }
      }
    }

    if (dist[t] == INF) return -1;

    rep(v, V) h[v] += dist[v];

    int d = f;
    for (int v = t; v != s; v = prevv[v]) {
      d = min(d, G[prevv[v]][preve[v]].cap);
    }

    f -= d;
    res += d * h[t];

    for (int v = t; v != s; v = prevv[v]) {
      edge &e = G[prevv[v]][preve[v]];
      e.cap -= d;
      G[v][e.rev].cap += d;
    }
  }

  return res;
}

int main() {
  while (1) {
    int N;
    cin >> N;
    if (N == 0) break;
    rep(i, V) G[i].clear();
    rep(i, V - 1) add_edge(i, i + 1, 2, 0);
    rep(i, N) {
      int a, b, c;
      cin >> a >> b >> c;
      add_edge(a - 1, b, 1, c);
    }

    cout << -min_cost_flow(0, 365, 2) << endl;
  }

  return 0;
}