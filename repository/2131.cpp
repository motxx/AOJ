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

double const PI = acos(-1);

int solve(int deno, double R) {
  int L = (PI - R) * deno, U = ceil(PI + R) * deno;
  bool ok = 0;
  while (U - L > 1) {
    int M = (L + U) / 2.0;
    if (abs(double(M) / deno - PI) <= R) {
      ok = 1;
      L = M;
    } else {
      U = M;
    }
  }
  return ok ? L : -inf;
}

int main() {
  double R;
  while (cin >> R && R != 0.0) {
    rep(deno, 10000000) {
      int n = solve(deno + 1, R);
      if (n != -inf) {
        printf("%d/%d\n", n, deno + 1);
        break;
      }
    }
  }

  return 0;
}