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
vector<pair<char, int>> v;
int idx;

int solve() {
  int d = v[idx].first;
  char c = v[idx].second;
  idx++;
  if (isdigit(c)) {
    return c - '0';
  } else {
    int ret = c == '*';
    while (idx < N && d < v[idx].first) {
      if (c == '*')
        ret *= solve();
      if (c == '+')
        ret += solve();
    }
    return ret;
  }
}

int main() {

  while (cin >> N && N) {
    v.clear();
    rep(i, N) {
      string s;
      cin >> s;
      v.push_back({s.size() - 1, s.back()});
    }

    idx = 0;
    cout << solve() << endl;
  }

  return 0;
}