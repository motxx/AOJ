#include <algorithm>
#include <array>
#include <assert.h>
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

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a)                                                               \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2> inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2> inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

int N;

int solve(string &s, string &t) {
  rep(i, N) s[i] -= '0', t[i] -= '0';
  queue<string> q;
  q.push(s);
  unordered_map<string, int> dist;
  dist[s] = 0;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    int d = dist[u];
    int idx = 0;
    while (idx < N && u[idx] == t[idx])
      idx++;
    if (idx == N)
      break;
    int m = (t[idx] - u[idx] + 10) % 10;

    // 未確定部分のはじめのダイアルから、連続1個以上を回す
    REP(i, idx, N) {
      u[i] = (u[i] + m) % 10;
      if (dist.find(u) == dist.end()) {
        dist[u] = d + 1;
        q.push(u);
      }
    }
  }
  return dist[t];
}

int main() {
  while (cin >> N && N) {
    string s, t;
    cin >> s >> t;
    cout << solve(s, t) << endl;
  }
}