#include <bits/stdc++.h>

using namespace std;

int V, E, L;

int const INF = 1 << 28;

struct Edge {
  int src, dst, dist, ene;
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

Graph G;

struct State {
  int money, attacked, pos;
  bool operator<(const State& s) const { return attacked > s.attacked; }
};

int dijkstra(int st) {
  int dist[110][110];  // [node][money]

  fill(dist[0], dist[0] + 110 * 110, INF);
  dist[st][L] = 0;

  priority_queue<State> pq;
  pq.push((State){L, 0, st});
  while (!pq.empty()) {
    const State stt = pq.top();
    pq.pop();
    if (stt.attacked > dist[stt.pos][stt.money]) continue;

    for (int i = 0; i < G[stt.pos].size(); i++) {
      int next = G[stt.pos][i].dst;
      int nmoney = stt.money - G[stt.pos][i].dist;

      if (nmoney < 0) continue;
      if (dist[next][nmoney] > stt.attacked) {
        dist[next][nmoney] = stt.attacked;
        pq.push((State){nmoney, stt.attacked, next});
      }
    }

    for (int i = 0; i < G[stt.pos].size(); i++) {
      int next = G[stt.pos][i].dst;
      int nattacked = stt.attacked + G[stt.pos][i].ene;
      if (dist[next][stt.money] > nattacked) {
        dist[next][stt.money] = nattacked;
        pq.push((State){stt.money, nattacked, next});
      }
    }
  }

  int mn = INF;
  for (int i = 0; i <= L; i++) {
    mn = min(mn, dist[V - 1][i]);
  }

  return mn;
}

int main() {
  while (cin >> V >> E >> L && (V | E | L)) {
    G.resize(V);
    for (int i = 0; i < V; i++) {
      G[i].clear();
    }
    for (int i = 0; i < E; i++) {
      int a, b, d, e;
      cin >> a >> b >> d >> e;
      a--, b--;
      G[a].push_back((Edge){a, b, d, e});
      G[b].push_back((Edge){b, a, d, e});
    }

    cout << dijkstra(0) << endl;
  }
  return 0;
}