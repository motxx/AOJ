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
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;

int const inf = 1e9;

template <class T>
using PQ_G = priority_queue<T, vector<T>, greater<T>>;

ll dist[100][25];
ll bitcost[1 << 8];
typedef tuple<int, int, int> state;  // cost, time, pos

typedef tuple<int, ll, int, int> edge;
vector<vector<edge>> g;

int dijkstra(int start, int goal, int H, int S) {
  PQ_G<state> pq;
  pq.emplace(0, 0, start);

  while (!pq.empty()) {
    ll cost, stime;
    int pos;
    tie(cost, stime, pos) = pq.top();
    pq.pop();

    if (pos == goal) return cost;

    for (auto &&e : g[pos]) {
      int b, c, h, r;
      tie(b, c, h, r) = e;
      ll ntime = stime + h;
      if (ntime > H) continue;
      if (S >> r & 1) {
        if (dist[b][ntime] <= cost) continue;
        dist[b][ntime] = cost;
        pq.emplace(dist[b][ntime], ntime, b);
      } else {
        ll ncost = cost + c;
        if (dist[b][ntime] <= ncost) continue;
        dist[b][ntime] = ncost;
        pq.emplace(dist[b][ntime], ntime, b);
      }
    }
  }
  return inf;
}

signed main() {
  int N, M, H, K;
  while (cin >> N >> M >> H >> K && (N | M | H | K)) {
    g.clear();
    g.resize(N);

    rep(i, M) {
      int a, b, c, h, r;
      cin >> a >> b >> c >> h >> r;
      a--, b--;
      r--;
      g[a].emplace_back(b, c, h, r);
      g[b].emplace_back(a, c, h, r);
    }

    int start, goal;
    cin >> start >> goal;
    start--, goal--;

    rep(i, 1 << 8) bitcost[i] = inf;
    bitcost[0] = 0;

    int P;
    cin >> P;

    rep(i, P) {
      int l, d;
      cin >> l >> d;
      int S = 0;
      rep(j, l) {
        int k;
        cin >> k;
        k--;
        S |= 1 << k;
      }
      bitcost[S] = d;
    }

    rep(S, 1 << K) {
      if (bitcost[S] >= inf) continue;
      rep(T, 1 << K) {
        if (bitcost[T] >= inf) continue;
        bitcost[S | T] = min(bitcost[S | T], bitcost[S] + bitcost[T]);
      }
    }

    ll ans = inf;

    rep(S, 1 << K) {
      rep(i, 100) rep(j, 25) dist[i][j] = inf;
      dist[start][0] = 0;
      if (bitcost[S] < inf)
        minimize(ans, dijkstra(start, goal, H, S) + bitcost[S]);
    }

    cout << (ans == inf ? -1 : ans) << endl;
  }

  return 0;
}