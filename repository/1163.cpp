#define _GLIBCXX_DEBUG
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) : src(src), dst(dst), weight(weight) {}
};
bool operator<(const Edge& e, const Edge& f) {
  return e.weight != f.weight ? e.weight > f.weight :  // !!INVERSE!!
             e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool augment(const Graph& g, int u, vector<int>& matchTo,
             vector<bool>& visited) {
  if (u < 0) return true;
  FOR(e, g[u]) if (!visited[e->dst]) {
    visited[e->dst] = true;
    if (augment(g, matchTo[e->dst], matchTo, visited)) {
      matchTo[e->src] = e->dst;
      matchTo[e->dst] = e->src;
      return true;
    }
  }
  return false;
}

int bipartiteMatching(const Graph& g, int L) {
  const int n = g.size();
  vector<int> matchTo(n, -1);
  int match = 0;
  REP(u, L) {
    vector<bool> visited(n);
    if (augment(g, u, matchTo, visited)) ++match;
  }

  return match;
}

int main() {
  int blue[500], red[500];
  int m, n;

  while (cin >> m >> n && (m | n)) {
    Graph g(m + n);
    REP(i, m) cin >> blue[i];
    REP(i, n) cin >> red[i];

    REP(i, m) REP(j, n) {
      if (__gcd(blue[i], red[j]) > 1) {
        g[i].push_back(Edge(i, m + j, 1));
        g[m + j].push_back(Edge(m + j, i, 1));
      }
    }

    cout << bipartiteMatching(g, m) << endl;
  }
  return 0;
}