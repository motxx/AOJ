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
  for (int N, M; cin >> N >> M && (N | M);) {
    vector<int> v(N);
    rep(i, N) cin >> v[i];
    int mnn = inf, mn = inf, idx = -1;
    bool multiple = 0;

    rep(i, N) {
      if (mnn > v[i] * (M / v[i])) {
        mnn = v[i] * (M / v[i]);
        mn = v[i];
        idx = i;
        multiple = 0;
      } else if (mnn == v[i] * (M / v[i]) && mn > v[i]) {
        mn = v[i];
        idx = i;
        multiple = 0;
      } else if (mnn == v[i] * (M / v[i]) && mn == v[i]) {
        multiple = 1;
      }
    }

    if (multiple) {
      cout << N << endl;
    } else {
      cout << idx + 1 << endl;
    }
  }

  return 0;
}