#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int d[101];
int V, E;

struct edge {
  int from, to, cost;
};

vector<edge> es;

bool find_negative_loop() {
  memset(d, 0, sizeof(d));

  for (int i = 0; i < V; i++) {
    for (int j = 0; j < E; j++) {
      edge e = es[j];
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i == V - 1) return true;
      }
    }
  }
  return false;
}

int main() {
  int s, t;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    cin >> s >> t;
    s--, t--;
    es.push_back((edge){s, t, -1});
  }

  cout << find_negative_loop() << endl;

  return 0;
}