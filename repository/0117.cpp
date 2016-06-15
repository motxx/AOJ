#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

#define INF 1 << 20
#define MAX_V 20

struct Edge {
  int to, cost;
};

typedef pair<int, int> Pii;  // cost, vertex

int V;
int d[MAX_V];

vector<Edge> G[MAX_V];

int dijkstra(int s, int t) {
  priority_queue<Pii> Q;
  fill(d, d + V, INF);
  d[s] = 0;
  Q.push(Pii(0, s));

  while (!Q.empty()) {
    Pii p = Q.top();
    Q.pop();
    int v = p.second;

    if (d[v] < p.first) continue;

    for (int i = 0; i < G[v].size(); i++) {
      Edge e = G[v][i];

      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        Q.push(Pii(d[e.to], e.to));
      }
    }
  }

  return d[t];
}

int main() {
  int m;
  cin >> V >> m;
  char dd;

  for (int i = 0; i < m; i++) {
    int a, b, c, d;
    cin >> a >> dd >> b >> dd >> c >> dd >> d;
    a--, b--;
    G[a].push_back((Edge){b, c});
    G[b].push_back((Edge){a, d});
  }

  int x1, x2, y1, y2;
  cin >> x1 >> dd >> x2 >> dd >> y1 >> dd >> y2;
  x1--, x2--;

  int ret = y1 - y2;
  ret -= dijkstra(x1, x2);
  ret -= dijkstra(x2, x1);

  cout << ret << endl;
  return 0;
}