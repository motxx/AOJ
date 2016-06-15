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
  cin.ignore();
  vector<string> v(N);
  rep(i, N) {
    getline(cin, v[i]);
    if (v[i].back() == ';') v[i] = v[i].substr(0, v[i].size() - 1);
    if (v[i].back() == ':') v[i] = v[i].substr(0, v[i].size() - 1);
  }

  vector<pair<int, int>> g[101];

  rep(i, N) {
    if (v[i].size() < 4 || v[i].substr(0, 4) != "goto") {
      g[i].emplace_back(0, i + 1);
    } else {
      string label = v[i].substr(5);
      int to = find(all(v), label) - v.begin();
      g[i].emplace_back(0, to);
      g[i].emplace_back(1, i + 1);
    }
  }

  deque<pair<int, int>> q;
  q.emplace_back(0, 0);

  int dist[101];
  rep(i, 101) dist[i] = inf;
  dist[0] = 0;

  while (!q.empty()) {
    int cost, pos;
    tie(cost, pos) = q.front();
    q.pop_front();
    if (pos == N) {
      cout << cost << endl;
      return 0;
    }
    for (auto e : g[pos]) {
      int pc = e.first;
      int to = e.second;
      if (dist[to] > cost + pc) {
        dist[to] = cost + pc;
        if (pc == 1) {
          q.emplace_back(dist[to], to);
        } else {
          q.emplace_front(dist[to], to);
        }
      }
    }
  }

  cout << 0 << endl;

  return 0;
}