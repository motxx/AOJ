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

namespace math {
namespace integer {

template <class value_type>
value_type mod_mul(value_type x, value_type k, value_type m) {
  if (k == 0) {
    return 0;
  }
  if (k % 2 == 0) {
    return mod_mul((x + x) % m, k / 2, m);
  } else {
    return (x + mod_mul(x, k - 1, m)) % m;
  }
}
template <class value_type>
value_type mod_pow(value_type x, value_type n, value_type mod) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return mod_pow(mod_mul(x, x, mod) % mod, n / 2, mod);
  } else {
    return mod_mul(x, mod_pow(x, n - 1, mod), mod);
  }
}
template <class value_type>
value_type extgcd(value_type a, value_type b, value_type& x, value_type& y) {
  value_type d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}
template <class value_type>
value_type mod_inverse(value_type x, value_type mod) {
  return mod_pow(x, mod - 2, mod); /* use fermat */
}
template <class value_type>
value_type mod_inverse_unusual_mod(value_type a, value_type mod) {
  value_type x, y;
  extgcd(a, mod, x, y);
  return (mod + x % mod) % mod;
}
}
}

int main() {
  int a, b;
  cin >> a >> b;
  int x, y;
  math::integer::extgcd(a, b, x, y);
  cout << x << " " << y << endl;

  return 0;
}