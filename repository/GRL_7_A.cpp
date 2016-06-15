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
  int X, Y, E;

  cin >> X >> Y >> E;
  Graph g(X + Y);

  for (int i = 0; i < E; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(Edge(x, X + y, 1));
    g[X + y].push_back(Edge(X + y, x, 1));
  }

  cout << bipartiteMatching(g, X) << endl;

  return 0;
}