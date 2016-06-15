#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef vector<int> Edge;
typedef vector<Edge> Graph;

Graph g;
set<int> ans;

vector<bool> vis;

void dfs(int x) {
  vis[x] = 1;
  if (g[x].empty()) {
    ans.insert(x);
    return;
  }

  rep(i, g[x].size()) {
    if (vis[g[x][i]]) continue;
    dfs(g[x][i]);
  }
}

int main() {
  int N;
  while (cin >> N && N) {
    vis.clear();
    ans.clear();
    g.clear();

    int id_size = 0;
    map<string, int> id;

    cin.ignore();
    rep(ii, N) {
      string str;
      getline(cin, str);

      rep(i, str.size()) {
        if (!isalpha(str[i])) str[i] = ' ';
      }
      stringstream ss(str);

      string parent;
      ss >> parent;
      if (id.find(parent) == id.end()) {
        id[parent] = id_size++;
      }

      while (ss >> str) {
        if (id.find(str) == id.end()) {
          id[str] = id_size++;
        }
        g.resize(id_size);
        vis.resize(id_size);
        g[id[parent]].push_back(id[str]);
      }
    }

    dfs(0);
    cout << ans.size() << endl;
  }

  return 0;
}