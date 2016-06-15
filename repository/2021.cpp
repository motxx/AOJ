#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int to, cost;
  Edge(int t, int c) : to(t), cost(c) {}
};

struct State {
  int cost, m, pos;
  State(int c, int m, int p) : cost(c), m(m), pos(p) {}
  bool operator<(const State& s) const { return cost > s.cost; }
};

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

#define MP make_pair

#define FST first
#define SND second

#define INF ((int)1e9)

int N, LIM, EST, ROAD, src, dst;
bool estb[100];
vector<Edge> G[100];
int cost[100][110];  // cost[N][LIM]

int dijkstra(int src, int dst) {
  fill(cost[0], cost[0] + 11000, INF);

  priority_queue<State> pq;
  pq.push(State(0, LIM, src));  // cost, m, now

  while (!pq.empty()) {
    State st = pq.top();
    pq.pop();

    if (st.pos == dst) {
      return st.cost;
    }

    if (cost[st.pos][st.m] < st.cost) {
      continue;
    }

    if (estb[st.pos] == 1 && st.m + 1 <= LIM) {
      // 冷凍中
      if (cost[st.pos][st.m + 1] > st.cost + 1) {
        cost[st.pos][st.m + 1] = st.cost + 1;
        pq.push(State(st.cost + 1, st.m + 1, st.pos));
      }
    }

    for (int i = 0; i < G[st.pos].size(); i++) {
      const int next = G[st.pos][i].to;
      const int add_cost = G[st.pos][i].cost;
      const int moved_m = st.m - add_cost;

      if (moved_m < 0) {
        continue;
      }  // 到達不可

      if (cost[next][moved_m] > st.cost + add_cost) {
        cost[next][moved_m] = st.cost + add_cost;
        pq.push(State(st.cost + add_cost, moved_m, next));
      }
    }
  }

  return -1;
}

int main() {
  while (cin >> N >> LIM >> EST >> ROAD >> src >> dst && N) {
    for (int i = 0; i < 100; i++) {
      G[i].clear();
      estb[i] = 0;
    }
    for (int i = 0; i < EST; i++) {
      int a;
      cin >> a;
      estb[a] = 1;
    }

    for (int i = 0; i < ROAD; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      G[a].push_back(Edge(b, c));
      G[b].push_back(Edge(a, c));
    }

    int ret = dijkstra(src, dst);
    if (ret == -1) {
      cout << "Help!" << endl;
    } else {
      cout << ret << endl;
    }
  }
  return 0;
}