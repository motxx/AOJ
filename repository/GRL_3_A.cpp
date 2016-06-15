#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int const INF = 1 << 29;

typedef vector<int> edges;
typedef vector<edges> graph;

namespace articulation {

int const MaxNum = 100000;

int prenum[MaxNum];
int lowest[MaxNum];
int parent[MaxNum];
int timer;
int V;

bool visited[MaxNum];
graph g;

void dfs(int curr) {
  prenum[curr] = timer;
  lowest[curr] = timer;
  timer++;

  visited[curr] = 1;

  rep(i, g[curr].size()) {
    int next = g[curr][i];
    if (!visited[next]) {
      parent[next] = curr;
      dfs(next);
      lowest[curr] = min(lowest[curr], lowest[next]);
    } else if (next != curr) {
      lowest[curr] = min(lowest[curr], prenum[next]);
    }
  }
}

vector<int> doit(int V_) {
  V = V_;
  rep(i, V) { visited[i] = 0; }
  timer = 1;
  dfs(0);

  vector<int> ret;
  int cnt = 0;
  rep(i, V) {
    if (i && parent[i] == 0) {
      cnt++;
    }
    if (parent[i] > 0 && lowest[i] >= prenum[parent[i]]) {
      ret.push_back(parent[i]);
    }
  }
  if (cnt >= 2) {
    ret.push_back(0);
  }
  sort(ret.begin(), ret.end());
  ret.erase(unique(ret.begin(), ret.end()), ret.end());
  return ret;
}
}

int main() {
  using namespace articulation;

  int N, M;
  cin >> N >> M;
  g.resize(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> arts = doit(N);

  rep(i, arts.size()) { cout << arts[i] << endl; }

  return 0;
}