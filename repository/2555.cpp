#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()

int const inf = 1 << 29;

bool isDAG(vector<vector<int>>& G) {
  int N = G.size();
  vector<bool> vis(N);

  std::function<bool(int, unordered_set<int>&)> dfs = [&](
      int curr, unordered_set<int>& st) {
    for (auto&& e : G[curr]) {
      if (st.count(e)) return false;
      if (vis[e]) continue;
      st.insert(e);
      vis[e] = 1;
      if (!dfs(e, st)) return false;
      st.erase(e);
    }
    return true;
  };

  rep(e, N) {
    vis[e] = 1;
    unordered_set<int> st = {e};
    if (!dfs(e, st)) return false;
  }
  return true;
}

int main() {
  int M, N;
  cin >> M >> N;
  vector<vector<pair<int, int>>> cmd_sect(N,
                                          vector<pair<int, int>>(M, {0, inf}));

  rep(cmd_idx, M) {
    int K;
    cin >> K;
    rep(_, K) {
      int skill;
      cin >> skill;
      skill--;
      string op;
      cin >> op;
      int threshold;
      cin >> threshold;
      if (op == ">=") {
        cmd_sect[skill][cmd_idx].first =
            max(cmd_sect[skill][cmd_idx].first, threshold);
      } else {
        cmd_sect[skill][cmd_idx].second =
            min(cmd_sect[skill][cmd_idx].second, threshold);
      }
      if (cmd_sect[skill][cmd_idx].first > cmd_sect[skill][cmd_idx].second) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  vector<vector<int>> G(M);

  rep(i, N) {
    rep(a, M) rep(b, M) {
      if (a == b) continue;
      if (cmd_sect[i][a].second < cmd_sect[i][b].first) G[a].push_back(b);
    }
  }

  rep(i, M) {
    sort(all(G[i]));
    G[i].erase(unique(all(G[i])), G[i].end());
  }

  cout << (isDAG(G) ? "Yes" : "No") << endl;

  return 0;
}