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

template <class T, class ResultType = long long>
vector<ResultType> binary_representation(T x, int const LeastDigit = 0) {
  if (x == 0) return {0};
  vector<ResultType> ret;
  while (x > 0) {
    ret.push_back(x % 2);
    x /= 2;
  }
  while ((int)ret.size() < LeastDigit) {
    ret.push_back(0);
  }
  reverse(all(ret));
  return ret;
}
template <class T>
ostream& operator<<(ostream& ost, vector<T>&& v) {
  for (auto&& e : v) ost << e;
  return ost;
}
template <class T>
ostream& operator<<(ostream& ost, vector<T> const& v) {
  ost << "[";
  rep(i, v.size()) {
    if (i) ost << ", ";
    ost << v[i];
  }
  ost << "]";
  return ost;
}

int main() {
  string pstr;
  rep(i, 10) pstr += '0' + i;
  rep(i, 26) pstr += 'A' + i;
  rep(i, 26) pstr += 'a' + i;

  int N;
  cin >> N;

  bool ok = 0;

  ll s = 0;
  rep(i, N) {
    ll p;
    string m;
    cin >> p >> m;
    ll x = 0;
    ll u = 1;
    reverse(all(m));
    rep(i, m.size()) {
      x += pstr.find(m[i]) * u;
      u *= p;
    }

    auto vx = binary_representation(x);

    int cnt = 0;
    rep(i, vx.size()) {
      if (vx[i] == 0 && cnt > 0) {
        s ^= cnt;
        cnt = 0;
      } else {
        if (vx[i] == 1) {
          ok = 1;
          cnt++;
        }
      }
    }
    if (cnt) s ^= cnt;
  }

  if (!ok) {
    cout << "lose" << endl;
  } else {
    cout << (s ? "win" : "lose") << endl;
  }

  return 0;
}