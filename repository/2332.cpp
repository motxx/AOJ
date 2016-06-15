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
int const inf = 1 << 29;

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> g(N);
  rep(i, N) {
    int p;
    cin >> p;
    if (p != 0) {
      g[i].emplace_back(0, i + p);
    } else {
      REP(j, 1, 7) { g[i].emplace_back(1, min(i + j, N - 1)); }
    }
  }

  vector<int> vis(N, inf);
  vis[0] = 0;
  deque<pair<int, int>> q;
  q.emplace_back(0, 0);
  while (!q.empty()) {
    auto p = q.front();
    q.pop_front();
    int co = p.first, po = p.second;
    if (po == N - 1) {
      cout << co << endl;
      break;
    }

    for (auto &&e : g[po]) {
      int pcost = e.first, to = e.second;
      if (vis[to] > co + pcost) {
        vis[to] = co + pcost;
        if (pcost == 0) {
          q.emplace_front(vis[to], to);
        } else {
          q.emplace_back(vis[to], to);
        }
      }
    }
  }

  return 0;
}