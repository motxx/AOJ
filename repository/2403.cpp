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

int N;
map<string, int> id;
bool adjacent[41][41];
int weight[41], wes[41];
int ans;

void dfs(ll S, int wsum, int curr) {
  if (wsum + wes[N - 1] - (curr ? wes[curr] : 0) <= ans) return;
  if (curr == N - 1) {
    ans = max(ans, wsum);
    return;
  }
  const int next = curr + 1;
  dfs(S, wsum, next);
  rep(k, next) if (adjacent[next][k] && (S >> k & 1)) return;
  dfs(S | (1LL << next), wsum + weight[next], next);
}

int main() {
  while (cin >> N && N) {
    rep(i, 41) weight[i] = 0;
    rep(i, 41) rep(j, 41) adjacent[i][j] = 0;
    id.clear();
    int v = 0;

    rep(i, N) {
      string s;
      cin >> s;
      if (id.find(s) == id.end()) id[s] = v++;
      cin >> weight[id[s]];
      int n;
      cin >> n;
      rep(_, n) {
        string t;
        cin >> t;
        if (id.find(t) == id.end()) id[t] = v++;
        adjacent[id[s]][id[t]] = 1;
      }
    }

    rep(i, N) wes[i] = weight[i] + (i ? wes[i - 1] : 0);

    ans = 0;
    dfs(1LL << 0, weight[0], 0);

    cout << ans << endl;
  }

  return 0;
}