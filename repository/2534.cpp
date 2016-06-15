#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

const char premark = 'a' - 1;

bool dfs(map<char, vector<char>>& G, vector<bool>& vis, char c) {
  for (auto& next : G[c]) {
    if (vis[next - 'a']) return false;
    vis[next - 'a'] = 1;
    if (!dfs(G, vis, next)) return false;
    vis[next - 'a'] = 0;
  }
  return true;
}

void NG() { cout << "no" << endl; }

int main() {
  for (int N; cin >> N && N;) {
    vector<string> v;
    int L = 1;
    rep(i, N) {
      string s;
      cin >> s;
      v.push_back(s);
      maximize(L, s.size());
    }
    rep(i, N) { v[i].resize(L, premark); }

    map<char, vector<char>> G;
    vector<bool> vis;

    rep(i, N - 1) {
      REP(ni, i + 1, N) {
        rep(j, L) {
          if (v[i][j] == v[ni][j] && v[i][j] == premark) break;
          if (v[i][j] == premark) break;
          if (v[ni][j] == premark) {
            NG();
            goto ex;
          }
          if (v[i][j] == v[ni][j]) continue;
          G[v[i][j]].push_back(v[ni][j]);
          break;
        }
      }
    }

    REP(c, 'a', 'z' + 1) if (!G[c].empty()) {
      sort(all(G[c]));
      G[c].erase(unique(all(G[c])), G[c].end());
    }

    REP(c, 'a', 'z' + 1) {
      vis.clear();
      vis.resize(26);
      vis[c - 'a'] = 1;
      if (!dfs(G, vis, c)) {
        NG();
        goto ex;
      }
    }

    cout << "yes" << endl;
  ex:;
  }

  return 0;
}