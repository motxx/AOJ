#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#define MAX (10010)

class UnionFind {
 private:
  int par[MAX];
  int rank[MAX];

 public:
  void init() {
    for (int i = 0; i < MAX; i++) {
      par[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x) {
    if (par[x] == x) {
      return x;
    }
    return par[x] = find(par[x]);
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }

  UnionFind() { init(); }
};

struct Edge {
  int from, to, cost;
  Edge(int f = -1, int t = -1, int c = -1) : from(f), to(t), cost(c) {}
};

bool comp(const Edge& a, const Edge& b) { return a.cost < b.cost; }

int kruskal(vector<Edge>& edges) {
  sort(edges.begin(), edges.end(), comp);
  UnionFind uf;
  vector<int> vec;
  for (int i = 0; i < edges.size(); i++) {
    Edge e = edges[i];
    if (!uf.same(e.from, e.to)) {
      uf.unite(e.from, e.to);
      vec.push_back(edges[i].cost);
    }
  }
  sort(vec.begin(), vec.end());

  return vec[vec.size() / 2];
}

int main() {
  int n, m;
  while (cin >> n >> m && (n | m)) {
    vector<Edge> es;
    for (int i = 0; i < m; i++) {
      int s, t, c;
      cin >> s >> t >> c;
      s--, t--;
      es.push_back(Edge(s, t, c));
    }
    cout << kruskal(es) << endl;
  }

  return 0;
}