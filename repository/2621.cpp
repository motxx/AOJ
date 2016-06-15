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
int const inf = 1 << 29;

int main() {
  int N;
  scanf("%d", &N);
  map<pair<int, int>, ll> mp;
  vector<pair<int, int>> vs;
  rep(i, N) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    vs.emplace_back(x, y);
    mp[{x, y}] += w;
  }

  ll ans = 0;

  rep(i, vs.size()) {
    int x = vs[i].first, y = vs[i].second;
    REP(dx, -1, 2) REP(dy, -1, 2) {
      if (!dx || !dy) continue;
      maximize(ans, mp[{x, y}] + mp[{x + dx, y}] + mp[{x, y + dy}] +
                        mp[{x + dx, y + dy}]);
    }
  }

  cout << ans << " / 1" << endl;

  return 0;
}