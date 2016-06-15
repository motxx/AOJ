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

int get_exp(string x) { return stoi(x.substr(3)); }

bool dfs(string& s, int num, map<string, vector<pair<int, string>>>& G,
         map<string, int>& vis) {
  for (auto& e : G[s]) {
    int r;
    string next;
    tie(r, next) = e;
    auto iter = vis.find(next);

    if (iter != vis.end()) {
      if (num + r != iter->second) return false;
    } else {
      vis[next] = num + r;
      if (!dfs(next, num + r, G, vis)) return false;
    }
  }
  return true;
}

int main() {
  int N;
  while (cin >> N && N) {
    map<string, vector<pair<int, string>>> G;
    set<string> st;

    rep(__, N) {
      char _;
      string s1, s2, t;
      cin >> _ >> s1 >> _ >> t >> s2;
      G[s1].emplace_back(get_exp(t), s2);
      G[s2].emplace_back(get_exp(t) * -1, s1);
      st.insert(s1), st.insert(s2);
    }

    map<string, int> vis;
    bool ok = 1;
    for (auto s : st) {
      if (vis.find(s) != vis.end()) continue;
      vis[s] = 1;
      if (!dfs(s, 1, G, vis)) {
        ok = 0;
        break;
      }
    }

    cout << (ok ? "Yes" : "No") << endl;
  }

  return 0;
}