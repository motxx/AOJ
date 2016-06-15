#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < int(b); i++)
#define rep(i, n) REP(i, 0, n)

#define INF (1e9)

int main() {
  int N;
  cin >> N;
  vector<vector<int>> v(N, vector<int>(N));
  rep(i, N) rep(j, N) { cin >> v[i][j]; }

  vector<int> V(N);
  iota(V.begin(), V.end(), 0);

  priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                 greater<pair<int, vector<int>>>>
      q;
  map<vector<int>, int> mp;
  mp[V] = 0;
  q.emplace(0, V);
  while (!q.empty()) {
    int co;
    vector<int> V;
    tie(co, V) = q.top();
    q.pop();

    rep(i, N) REP(j, i + 1, N) {
      swap(V[i], V[j]);
      if (mp.find(V) != mp.end() && mp[V] <= co + v[V[i]][V[j]]) {
        swap(V[i], V[j]);
        continue;
      }

      mp[V] = co + v[V[i]][V[j]];
      q.emplace(co + v[V[i]][V[j]], V);
      swap(V[i], V[j]);
    }
  }

  int ans = 0;

  for (auto&& e : mp) {
    ans = max(ans, e.second);
  }

  cout << ans << endl;

  return 0;
}