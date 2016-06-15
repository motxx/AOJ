#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
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
  int N, M;
  cin >> N >> M;
  vector<int> b(N);
  rep(i, N) cin >> b[i];
  vector<int> tb1, tb2;
  int flag = 0;
  rep(i, M) {
    int p;
    cin >> p;
    rep(j, p) {
      tb1.push_back(flag);
      tb2.push_back(flag ^ 1);
    }
    flag ^= 1;
  }
  set<vector<int>> st = {b};
  queue<pair<vector<int>, int>> q;
  q.emplace(b, 0);

  auto check_run_length = [&](vector<int> &v) { return v == tb1 || v == tb2; };

  while (!q.empty()) {
    vector<int> p;
    int cost;
    tie(p, cost) = q.front();
    q.pop();
    if (check_run_length(p)) {
      cout << cost << endl;
      return 0;
    }
    rep(i, N - 1) {
      swap(p[i], p[i + 1]);
      if (!st.count(p)) {
        q.emplace(p, cost + 1);
        st.insert(p);
      }
      swap(p[i], p[i + 1]);
    }
  }

  return 0;
}