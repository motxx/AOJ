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
double const EPS = 1e-6;

int main() {
  int N, K, T, U, V;
  double L;
  cin >> N >> K >> T >> U >> V >> L;
  set<int> D;
  rep(i, N) {
    int d;
    cin >> d;
    D.insert(d);
  }

  int ninjin = 0;
  double stime = 0.0;
  int zizoku = 0;

  // ﾃｨﾂｷﾂ敕ｩﾂ崢｢ﾃ｣ﾂつ?ﾃ｣ﾂ?堙｣ﾂ?､ﾃｩﾂ?ｲﾃ｣ﾂつ?｣ﾂつ?

  rep(len, L) {
    if (D.count(len)) {
      if (ninjin + 1 > K) {
        zizoku = V * T;
      } else {
        ninjin++;
      }
    }

    if (!zizoku && ninjin > 0) {
      ninjin--;
      zizoku = V * T;
    }

    if (zizoku) {
      zizoku--;
      stime += 1.0 / V;
    } else {
      stime += 1.0 / U;
    }
  }

  printf("%.10f\n", stime);

  return 0;
}