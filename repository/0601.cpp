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
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
ll const inf = 1e17;

template <class T>
using PQ_G = priority_queue<T, vector<T>, greater<T>>;

ll N, M, X;
vector<ll> v;
vector<vector<pair<int, ll>>> G;

ll solve() {
  vector<ll> dist(N + 1, inf);

  PQ_G<tuple<ll, ll, int>> pq;
  pq.emplace(0, X, 0);

  while (!pq.empty()) {
    ll T, H;
    int curr;
    tie(T, H, curr) = pq.top();
    pq.pop();

    if (curr == N - 1) {
      ll nT = T + v[N - 1] - H;
      if (dist[N] > nT) {
        dist[N] = nT;
        pq.emplace(nT, v[N - 1], N);
      }
      continue;
    }

    if (curr == N) return T;

    for (auto &e : G[curr]) {
      int next;
      ll mvt;
      tie(next, mvt) = e;
      ll nT = T + mvt;
      ll nH = H - mvt;
      if (H - mvt < 0) {
        if (H + (mvt - H) > v[curr]) continue;
        nT += mvt - H;
        nH = 0;
      } else if (H - mvt > v[next]) {
        nT += (H - mvt) - v[next];
        nH = H - ((H - mvt) - v[next]) - mvt;
        if (nH < 0) continue;
      }

      if (dist[next] > nT) {
        dist[next] = nT;
        pq.emplace(nT, nH, next);
      }
    }
  }
  return -1;
}

int main() {
  cin >> N >> M >> X;
  v.resize(N);
  G.resize(N);
  rep(i, N) cin >> v[i];
  rep(i, M) {
    int x, y;
    ll t;
    cin >> x >> y >> t;
    x--, y--;
    if (t <= v[x]) G[x].emplace_back(y, t);
    if (t <= v[y]) G[y].emplace_back(x, t);
  }

  cout << solve() << endl;

  return 0;
}