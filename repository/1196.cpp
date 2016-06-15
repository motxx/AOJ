#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Edge {
  int to, cost;
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef long long ll;
typedef pair<ll, ll> Pll;

int N;
int p[810];  // p[0] no use
ll allcost, delcost;

Graph G;
set<int> leaves;

Pll visit(int prev, int curr) {
  Pll r(0, curr);

  for (int i = 0; i < G[curr].size(); i++) {
    const Edge& e = G[curr][i];
    if (e.to != prev) {
      if (leaves.count(e.to)) continue;
      Pll t = visit(curr, e.to);
      t.first += e.cost;
      if (r.first < t.first) r = t;
    }
  }
  return r;
}

ll diameter(int s) {
  Pll r = visit(-1, s);
  Pll t = visit(-1, r.second);
  return t.first;
}

void setLeaves() {
  delcost = allcost;
  for (int i = 0; i < G.size(); i++) {
    if (G[i].size() == 1) {
      leaves.insert(i);
      delcost -= G[i][0].cost;
    }
  }
}

void init() {
  G.clear();
  G.resize(N);
  leaves.clear();
  allcost = 0;
  delcost = 0;
}

int main() {
  while (cin >> N && N) {
    init();

    for (int i = 1; i < N; i++) {
      cin >> p[i];
      p[i]--;
    }

    for (int i = 1; i < N; i++) {
      int x;
      cin >> x;
      G[i].push_back((Edge){p[i], x});
      G[p[i]].push_back((Edge){i, x});
      allcost += x;
    }
    setLeaves();
    for (int i = 0; i < N; i++) {
      if (leaves.count(i)) continue;
      cout << 2 * delcost + allcost - diameter(i) << endl;
      break;
    }
  }

  return 0;
}