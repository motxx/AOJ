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

struct state {
  int cost, use, pos;
  state(int c, int u, int p) : cost(c), use(u), pos(p) {}
};

vector<int> bfs(vector<vector<pair<int, bool>>>& G, int s, int t,
                int& shortestLen) {
  vector<int> dist(G.size(), inf), d2cnt(G.size() + 1);
  dist[s] = 0;

  queue<state> q;
  q.emplace(0, 0, s);

  while (!q.empty()) {
    const state s = q.front();
    q.pop();
    d2cnt[s.cost]++;
    for (auto& e : G[s.pos]) {
      const int next = e.first;
      if (dist[next] > s.cost + 1) {
        dist[next] = s.cost + 1;
        q.emplace(dist[next], 0, next);
      }
    }
  }

  shortestLen = dist[t];
  return d2cnt;
}

int main() {
  int N, M, s, t;
  cin >> N >> M >> s >> t;
  s--, t--;
  vector<vector<pair<int, bool>>> G(N);
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    G[x - 1].emplace_back(y - 1, false);
    G[y - 1].emplace_back(x - 1, false);
  }

  int shortestLen;
  auto d2cnt1 = bfs(G, s, t, shortestLen);
  auto d2cnt2 = bfs(G, t, s, shortestLen);

  ll ans = 0;

  rep(i, N) {
    if (shortestLen - i - 2 >= 0)
      ans += (ll)d2cnt1[i] * d2cnt2[shortestLen - i - 2];
  }

  cout << ans << endl;

  return 0;
}