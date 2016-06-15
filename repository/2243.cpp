#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
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

string S;

set<int> X[3] = {{1, 4, 7}, {2, 8}, {3, 6, 9}};

void solve() {
  int N = S.size();
  int ans = inf;
  rep(o, 2) {
    int res = 0;
    int s = 0;
    rep(i, N - 1) {
      if ((i + o + s) & 1) {
        if (S[i] == 2 && X[0].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 8 && X[0].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 3 && X[0].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 6 && X[0].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 9 && X[0].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 3 && X[1].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 6 && X[1].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 9 && X[1].count(S[i + 1])) {
          res++;
          s++;
        }
      } else {
        if (S[i] == 1 && X[1].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 4 && X[1].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 7 && X[1].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 1 && X[2].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 4 && X[2].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 7 && X[2].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 2 && X[2].count(S[i + 1])) {
          res++;
          s++;
        }
        if (S[i] == 8 && X[2].count(S[i + 1])) {
          res++;
          s++;
        }
      }
    }
    minimize(ans, res);
  }
  cout << ans << endl;
}

int main() {
  for (; cin >> S;) {
    if (S == "#") {
      break;
    }
    rep(i, S.size()) S[i] -= '0';
    solve();
  }

  return 0;
}