#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int N, M, C;

typedef long long ll;

struct Edge {
  int to;
  ll cost;
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Graph g;

double cntpath[110][110];

struct state {
  int curr;
  ll cost;
  bool operator<(state const& s) const { return cost > s.cost; }
};

struct ST {
  int curr;
  double prob;
};

ll const INF = 1LL << 40;

int main() {
  while (cin >> N >> M >> C && (N | M | C)) {
    g.clear();
    g.resize(N);

    rep(i, M) {
      int a, b;
      ll c;
      cin >> a >> b >> c;
      g[a].push_back((Edge){b, c});
      g[b].push_back((Edge){a, c});
    }

    ll dist[N][N];
    fill(dist[0], dist[0] + N * N, INF);

    rep(S, N) {
      dist[S][S] = 0;
      cntpath[S][S] = 1;
      priority_queue<state> pq;
      pq.push((state){S, dist[S][S]});
      while (!pq.empty()) {
        int curr = pq.top().curr;
        ll cost = pq.top().cost;
        pq.pop();

        rep(i, g[curr].size()) {
          Edge& e = g[curr][i];
          if (dist[S][e.to] == cost + e.cost) {
            cntpath[S][e.to] += cntpath[S][curr];
          }
          if (dist[S][e.to] <= cost + e.cost) {
            continue;
          }
          cntpath[S][e.to] = cntpath[S][curr];
          dist[S][e.to] = cost + e.cost;
          pq.push((state){e.to, dist[S][e.to]});
        }
      }
    }

    rep(i, C) {
      int q;
      cin >> q;
      if (dist[0][q] + dist[q][N - 1] == dist[0][N - 1]) {
        printf("%.10f\n",
               cntpath[0][q] / cntpath[0][N - 1] * cntpath[q][N - 1]);
      } else {
        printf("%.10f\n", 0.);
      }
    }
    cout << endl;
  }

  return 0;
}