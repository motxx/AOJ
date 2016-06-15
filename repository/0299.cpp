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

int N, M, p;

int go(int a, int b, int dir) {
  if (b > a && dir > 0) return b - a;
  if (a > b && dir < 0) return a - b;
  if (b < a && dir > 0) return b + N - a;
  return a + N - b;
}

int main() {
  cin >> N >> M >> p;
  vector<int> v(M);
  rep(i, M) { cin >> v[i]; }

  v.push_back(p);
  sort(all(v));
  M = v.size();
  int s = -1;
  rep(i, M) if (v[i] == p) {
    s = i;
    break;
  }

  int ans = min(go(v[s], v[(s + 1) % M], -1), go(v[s], v[(s - 1 + M) % M], +1));

  rep(tpoint, M) {
    if (tpoint == s) continue;
    ans = min(ans, go(v[s], v[tpoint % M], +1) +
                       go(v[tpoint], v[(tpoint + 1) % M], -1));
    ans = min(ans, go(v[s], v[tpoint % M], -1) +
                       go(v[tpoint], v[(tpoint - 1 + M) % M], +1));
  }

  cout << ans * 100 << endl;

  return 0;
}