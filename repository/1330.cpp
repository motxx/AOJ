#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

struct UnionFind {
  vector<int> rank, par, W;

  UnionFind(int n) {
    rank.resize(n);
    par.resize(n);
    rep(i, n) rank[i] = 1, par[i] = i;
    W.resize(n);
  }

  pair<int, int> find(int x) {
    if (x == par[x]) {
      return make_pair(x, 0);
    }
    pair<int, int> ret = find(par[x]);
    par[x] = ret.first;
    W[x] += ret.second;
    return make_pair(par[x], W[x]);
  }

  void unite(int u, int v, int c) {
    pair<int, int> px = find(u), py = find(v);
    int x = px.first, y = py.first;
    if (x == y) return;
    if (rank[x] > rank[y]) {
      par[y] = x;
      W[y] = c + W[u] - W[v];
    } else {
      par[x] = y;
      W[x] = -(c + W[u] - W[v]);
      if (rank[x] == rank[y]) {
        rank[y]++;
      }
    }
  }

  bool same(int u, int v) { return find(u).first == find(v).first; }

  // ﾃｩﾂ?催｣ﾂ?ｿﾃ｣ﾂ?ｮﾃ･ﾂｷﾂｮﾃ｣ﾂつ津ｧﾂｭﾂ氾｣ﾂ?暗｣ﾂつ?
  int diff(int u, int v) { return W[v] - W[u]; }
};

int main() {
  for (int N, M; cin >> N >> M && (N | M);) {
    UnionFind uf(N * 2);
    rep(i, M) {
      char op;
      cin >> op;
      int u, v;
      cin >> u >> v;
      if (op == '!') {
        int c;
        cin >> c;
        uf.unite(u, v, c);
      } else {
        if (uf.same(u, v)) {
          cout << uf.diff(u, v) << endl;
        } else {
          puts("UNKNOWN");
        }
      }
    }
  }

  return 0;
}