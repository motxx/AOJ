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

int N;
string s;

int expr(int l, int r);

int term(int l, int r) {
  if (l + 1 == r) {
    return s[l] - '0';
  }
  if (l >= r) {
    return 0;
  }

  int ret = 1;
  REP(i, l, r + 1) {
    if (i == r || s[i] == '*') {
      ret *= expr(l, i);
      l = i + 1;
    }
  }
  return ret;
}

int expr(int l, int r) {
  if (l + 1 == r) {
    return s[l] - '0';
  }
  if (l >= r) {
    return 0;
  }

  int ret = 0;
  REP(i, l, r + 1) {
    if (i == r || s[i] == '+') {
      ret += term(l, i);
      l = i + 1;
    }
  }
  return ret;
}

int expr2() {
  int ret = s[0] - '0';
  int f = 0;
  REP(i, 1, N) {
    if (s[i] == '+') {
      f = 1;
    } else if (s[i] == '*') {
      f = 2;
    } else {
      if (f == 1) {
        ret += s[i] - '0';
      } else if (f == 2) {
        ret *= s[i] - '0';
      } else {
        assert(0);
      }
    }
  }
  return ret;
}

int main() {
  cin >> s;
  N = s.size();

  auto m = expr(0, N);
  auto l = expr2();

  int n;
  cin >> n;
  if (n == m && n == l) {
    cout << "U" << endl;
  } else if (n == m) {
    cout << "M" << endl;
  } else if (n == l) {
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }

  return 0;
}