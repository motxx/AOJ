#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_E 1001
#define MAX_N 101

struct Edge {
  int u, v, cost;
};

Edge es[MAX_E];
int n, m;
int par[MAX_N], rank[MAX_N];

void init_union_find() {
  for (int i = 0; i < n; i++) {
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

bool issame(int x, int y) { return find(x) == find(y); }

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

bool comp(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }

int kruskal() {
  sort(es, es + m, comp);
  init_union_find();
  int res = 0;
  for (int i = 0; i < m; i++) {
    Edge e = es[i];
    if (!issame(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main() {
  while (cin >> n >> m && n + m) {
    for (int i = 0; i < m; i++) {
      cin >> es[i].u >> es[i].v >> es[i].cost;
    }
    cout << kruskal() << endl;
  }

  return 0;
}