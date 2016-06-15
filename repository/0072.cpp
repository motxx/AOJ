#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_V 100
#define INF 1 << 20

int cost[MAX_V + 1][MAX_V + 1];
int mincost[MAX_V + 1];
bool used[MAX_V + 1];
int V;

int prim() {
  for (int i = 0; i < V; i++) {
    mincost[i] = INF;
    used[i] = false;
  }
  mincost[0] = 0;
  int res = 0;

  while (true) {
    int v = -1;
    for (int u = 0; u < V; u++) {
      if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }
    if (v == -1) break;
    used[v] = true;
    res += mincost[v];

    for (int u = 0; u < V; u++) {
      mincost[u] = min(mincost[u], cost[v][u]);
    }
  }
  return res;
}

int main() {
  int m;
  int a, b, c;
  char d;

  while (cin >> V >> m) {
    fill(cost[0], cost[V], INF);
    while (m--) {
      cin >> a >> d >> b >> d >> c;
      c /= 100;
      c--;
      cost[a][b] = c;
      cost[b][a] = c;
    }
    cout << prim() << endl;
  }

  return 0;
}