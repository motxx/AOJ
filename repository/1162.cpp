#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct State {
  int prev;
  int now;
  int vel;  // 到着時
  double e_time;

  bool operator<(const State &s) const { return e_time > s.e_time; }

  State() {}
  State(int p, int n, int v, double t) : prev(p), now(n), vel(v), e_time(t) {}
};

struct Edge {
  int to;
  int cost;
  int lim;

  Edge() {}
  Edge(int t, int c, int l) : to(t), cost(c), lim(l) {}
};

const double Inf = 1 << 23;
int N, M;
vector<Edge> edges[30];
double G_time[31][30][31];  // u, v, vel -> e_time

double dijkstra(int s, int g) {
  fill(G_time[0][0], G_time[30][30], Inf);
  priority_queue<State> pq;

  pq.push(State(s, s, 0, 0.0));
  G_time[s][s][0] = 0.0;

  while (!pq.empty()) {
    const State st = pq.top();
    pq.pop();

    if (G_time[st.prev][st.now][st.vel] < st.e_time) {
      continue;
    }

    if (st.now == g && st.vel == 1) {
      return st.e_time;
    }

    for (int i = 0; i < edges[st.now].size(); i++) {
      const Edge &e = edges[st.now][i];

      if (e.to == st.prev) continue;

      for (int dvel = -1; dvel <= 1; dvel++) {
        int nvel = st.vel + dvel;
        // 速度制限
        if (1 <= nvel && nvel <= e.lim) {
          double ntime = st.e_time + (double)e.cost / nvel;
          if (G_time[st.now][e.to][nvel] > ntime) {
            G_time[st.now][e.to][nvel] = ntime;
            pq.push(State(st.now, e.to, nvel, ntime));
          }
        }
      }
    }
  }

  return 42;
}

int main() {
  int s, g;

  while (cin >> N >> M && (N | M)) {
    cin >> s >> g;
    s--, g--;

    for (int i = 0; i < N; i++) edges[i].clear();

    for (int i = 0; i < M; i++) {
      int x, y, d, c;
      cin >> x >> y >> d >> c;
      x--, y--;
      edges[x].push_back(Edge(y, d, c));
      edges[y].push_back(Edge(x, d, c));
    }

    double ans = dijkstra(s, g);
    if (ans == 42) {
      cout << "unreachable" << endl;
    } else {
      printf("%.5lf\n", ans);
    }
  }

  return 0;
}