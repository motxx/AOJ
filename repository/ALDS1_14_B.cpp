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
#include <memory>
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
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

constexpr long long to_int64(char x) { return (long long)x; }

template <class T>
struct RollingHash {  // not verified

  //  const array<int, 3> mods = {{int(1e9+7), int(1e9+9), int(1234567891)}}; //
  //  strong
  const array<int, 1> mods = {{int(1e9 + 7)}};  // weak
  const array<int, 3> Ks = {{1007, 1009, 1013}};
  const int ModsSize = mods.size();

  vector<T> S;
  vector<vector<long long>> hash;
  vector<vector<long long>> pow_table;

  void construct() {
    hash.resize(ModsSize);
    int n = S.size();
    rep(i, ModsSize) hash[i].resize(n + 1);
    rep(i, ModsSize) {
      for (int j = n - 1; j >= 0; j--) {
        hash[i][j] = hash[i][j + 1] * Ks[i];
        hash[i][j] += to_int64(S[j]);
        hash[i][j] %= mods[i];
      }
    }

    pow_table.resize(ModsSize);
    rep(i, ModsSize) pow_table[i].resize(n + 1);

    rep(i, ModsSize) {
      pow_table[i][0] = 1;
      REP(j, 1, n + 1) {
        pow_table[i][j] = (pow_table[i][j - 1] * Ks[i]) % mods[i];
      }
    }
  }

  RollingHash(vector<T> const& S) {
    this->S = S;
    construct();
  }

  RollingHash(string const& S) {
    int n = S.size();
    rep(i, n) { this->S.push_back(S[i]); }
    construct();
  }

  long long get_hash(int t, int start, int end) const {
    auto r = hash[t][start] - hash[t][end] * pow_table[t][end - start];
    r %= mods[t];
    if (r < 0) {
      r += mods[t];
    }
    return r;
  }

  // ???????????\????????¨??????MOD??§?????´?????????????????????????????????
  bool same(int a_start, int a_end, int b_start, int b_end) const {
    int const len = a_end - a_start;
    if (len != b_end - b_start) {
      return false;
    }
    rep(i, ModsSize) {
      if (get_hash(i, a_start, a_end) != get_hash(i, b_start, b_end)) {
        return false;
      }
    }
    return true;
  }

  // ????????????????????¨??????????????¨????????´???????????????
  bool same(int a_start, int a_end, int b_start, int b_end,
            RollingHash<T>* const& rh) const {
    if (rh == nullptr) {
      return same(a_start, a_end, b_start, b_end);
    }
    int const len = a_end - a_start;
    if (len != b_end - b_start) {
      return false;
    }
    rep(i, ModsSize) {
      if (get_hash(i, a_start, a_end) != rh->get_hash(i, b_start, b_end)) {
        return false;
      }
    }
    return true;
  }

  // ???????????§?°???????
  bool compare(int a_start, int a_end, int b_start, int b_end,
               RollingHash<T>* rh = nullptr) const {
    int a_len = a_end - a_start;
    int b_len = b_end - b_start;

    int len = min(a_len, b_len);
    int max_len = len + 1;
    int min_len = 0;

    // ???????????§?????´????????????????????¢?´¢??§?????????
    while (min_len + 1 < max_len) {
      int next_len = (min_len + max_len) / 2;
      if (same(a_start, a_start + next_len, b_start, b_start + next_len, rh)) {
        min_len = next_len;
      } else {
        max_len = next_len;
      }
    }

    if (a_start + min_len == a_end) {
      if (b_start + min_len == b_end) {
        return 0;
      } else {
        return -1;
      }
    } else {
      if (b_start + min_len == b_end) {
        return 1;
      } else {
        return S[a_start + min_len] == S[b_start + min_len];
      }
    }
  }
};

char ca[1000001];
char cb[10001];

int main() {
  scanf("%s %s", ca, cb);
  string a = ca, b = cb;
  RollingHash<char> ra(a), rb(b);
  int n = a.size(), m = b.size();
  if (n < m) {
    return 0;
  }

  auto rbptr = new RollingHash<char>(rb);

  rep(i, n - m + 1) {
    if (ra.same(i, i + m, 0, m, rbptr)) {
      printf("%d\n", i);
    }
  }

  delete rbptr;

  return 0;
}