#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to, cost;
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef pair<int, int> Pii;

int const INF = INT_MAX / 2;

Graph G;

int main() {
  int V, E, r;
  cin >> V >> E >> r;
  G.resize(V);
  for (int i = 0; i < E; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    G[s].push_back((Edge){t, d});
  }

  int dist[V];
  fill(dist, dist + V, INF);
  dist[r] = 0;
  priority_queue<Pii> pq;
  pq.push(Pii(0, r));
  while (!pq.empty()) {
    const Pii pii = pq.top();
    pq.pop();
    const int cost = -pii.first;
    const int now = pii.second;
    if (dist[now] < cost) continue;
    for (int i = 0; i < (int)G[now].size(); i++) {
      const Edge& e = G[now][i];
      if (dist[e.to] > cost + e.cost) {
        dist[e.to] = cost + e.cost;
        pq.push(Pii(-dist[e.to], e.to));
      }
    }
  }

  for (int i = 0; i < V; i++) {
    if (dist[i] == INF)
      cout << "INF" << endl;
    else
      cout << dist[i] << endl;
  }

  return 0;
}