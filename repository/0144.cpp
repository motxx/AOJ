#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> con[101];

#define INF ((int)1e9)

int bfs(int const S, int const T) {
  queue<pair<int, int> > q;
  int cost[101];
  fill(cost, cost + 100, INF);
  cost[S] = 0;
  q.push(make_pair(0, S));
  while (!q.empty()) {
    int now = q.front().second;
    int c = q.front().first;
    q.pop();
    int const size = con[now].size();
    for (int i = 0; i < size; i++) {
      if (cost[con[now][i]] < INF) continue;
      cost[con[now][i]] = c + 1;
      // cout <<   "cost: " <<   cost[con[now][i]] << endl;
      q.push(make_pair(c + 1, con[now][i]));
    }
  }

  return cost[T];
}

int main() {
  int n;
  cin >> n;
  for (int I = 0; I < n; I++) {
    int r, k;
    cin >> r >> k;
    r--;
    for (int i = 0; i < k; i++) {
      int t;
      cin >> t;
      t--;
      con[r].push_back(t);
    }
    // cout << "con["<<r<<"].size() " << con[r].size() << endl;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b, ttl;
    cin >> a >> b >> ttl;
    a--;
    b--;
    int ans;
    if ((ans = bfs(a, b) + 1) <= ttl) {
      cout << ans << endl;
    } else {
      cout << "NA" << endl;
    }
  }

  return 0;
}