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

int D;
int A[100001];
vector<int> dat[1 << 20];

void init(int k, int l, int r) {
  if (r - l == 1) {
    dat[k].push_back(A[l]);
  } else {
    int lch = k * 2 + 1, rch = k * 2 + 2;
    init(lch, l, (l + r) / 2);
    init(rch, (l + r) / 2, r);
    dat[k].resize(r - l);
    merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(),
          dat[k].begin());
  }
}

int query(int i, int j, int x, int k, int l, int r) {
  if (j <= l || r <= i) {
    return 0;
  } else if (i <= l && r <= j) {
    return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
  } else {
    int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
    int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
    return lc + rc;
  }
}

int main() {
  cin >> D;
  rep(i, D) cin >> A[i];

  init(0, 0, D);

  int Q;
  cin >> Q;

  rep(_, Q) {
    int l, r, e;
    cin >> l >> r >> e;
    l--, r--;
    int a = min(A[l], A[r]) - e;
    int b = max(A[l], A[r]) + e;
    cout << (query(l, r + 1, a - 1, 0, 0, D) - query(l, r + 1, b, 0, 0, D) +
             (r - l + 1))
         << endl;
  }

  return 0;
}