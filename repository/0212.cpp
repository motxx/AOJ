#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define INF ((int)1e9)

struct Edge {
  int to, cost;
  Edge(int t, int c) : to(t), cost(c) {}
};

typedef pair<int, int> Pii;
typedef pair<int, Pii> Piii;  // cost, cnum, node

vector<Edge> G[100];
int memo[100][10];

int dijkstra(int src, int dst, int cnum) {
  fill(memo[0], memo[0] + 1000, INF);

  priority_queue<Piii> pq;
  memo[src][cnum] = 0;
  pq.push(Piii(0, Pii(-cnum, src)));
  while (!pq.empty()) {
    int cost = pq.top().first;
    int cn = -pq.top().second.first;
    int now = pq.top().second.second;
    pq.pop();

    for (int i = 0; i < G[now].size(); i++) {
      int next = G[now][i].to;
      int add_c = G[now][i].cost;
      if (memo[next][cn] > cost + add_c) {
        pq.push(Piii(cost + add_c, Pii(-cn, next)));
        memo[next][cn] = cost + add_c;
      }
      if (cn - 1 < 0) continue;
      add_c /= 2;
      if (memo[next][cn - 1] > cost + add_c) {
        pq.push(Piii(cost + add_c, Pii(-(cn - 1), next)));
        memo[next][cn - 1] = cost + add_c;
      }
    }
  }

  return *min_element(memo[dst], memo[dst] + 10);
}

int main() {
  int C, N, M, S, D;
  while (cin >> C >> N >> M >> S >> D && (N | M)) {
    for (int i = 0; i < N; i++) {
      G[i].clear();
    }
    for (int i = 0; i < M; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      G[a].push_back(Edge(b, c));
      G[b].push_back(Edge(a, c));
    }

    S--, D--;
    cout << dijkstra(S, D, C) << endl;
  }

  return 0;
}