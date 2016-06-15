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

vector<pair<int, double>> dices[10];
double hanchoE;
int ns[10], ms[10];
int t;

bool solve() {
  rep(i, t) {
    double E = 0.0;
    double sumr = 0.0;
    rep(k, ms[i]) {
      E += dices[i][k].first * dices[i][k].second;
      sumr += dices[i][k].second;
    }
    E /= sumr;
    if (E > hanchoE + 0.0000001) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> t;
  rep(ii, t) {
    cin >> ns[ii] >> ms[ii];
    rep(i, ms[ii]) {
      int v;
      double r;
      cin >> v >> r;
      dices[ii].emplace_back(v, r);
    }
  }

  int p, q;
  cin >> p >> q;
  double sumr = 0.0;
  rep(i, q) {
    int v;
    double r;
    cin >> v >> r;
    hanchoE += v * r;
    sumr += r;
  }

  hanchoE /= sumr;
  cout << (solve() ? "YES" : "NO") << endl;

  return 0;
}