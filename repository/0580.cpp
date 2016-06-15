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
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

void compress(vector<int>& x1, vector<int>& x2, map<int, int>& unzip) {
  vector<int> xs;
  rep(i, x1.size()) {
    xs.push_back(x1[i]);
    xs.push_back(x2[i]);
  }

  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  vector<int> nx1, nx2;

  rep(i, x1.size()) {
    nx1.push_back(lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin());
    nx2.push_back(lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin());
    unzip[nx1.back()] = x1[i];
    unzip[nx2.back()] = x2[i];
  }
  x1 = nx1, x2 = nx2;
}

int a[333][333][333];

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> x1(N), y1(N), z1(N), x2(N), y2(N), z2(N);
  rep(i, N) { cin >> x1[i] >> y1[i] >> z1[i] >> x2[i] >> y2[i] >> z2[i]; }

  map<int, int> ux, uy, uz;
  compress(x1, x2, ux);
  compress(y1, y2, uy);
  compress(z1, z2, uz);

  rep(i, N) {
    REP(x, x1[i], x2[i])
    REP(y, y1[i], y2[i])
    REP(z, z1[i], z2[i])
    a[x][y][z]++;
  }

  ll ans = 0;
  rep(x, ux.size() - 1) rep(y, uy.size() - 1) rep(z, uz.size() - 1) {
    if (a[x][y][z] >= K) {
      ans +=
          (ll)(ux[x + 1] - ux[x]) * (uy[y + 1] - uy[y]) * (uz[z + 1] - uz[z]);
    }
  }

  cout << ans << endl;

  return 0;
}