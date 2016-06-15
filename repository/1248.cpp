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
value_type mod_mul(value_type x, value_type k, ll m) {
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
value_type mod_pow(value_type x, value_type n, ll mod) {
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
value_type mod_inverse(value_type x, ll mod) {
  return mod_pow(x, value_type(mod - 2), mod); /* use fermat */
}
template <class value_type>
value_type mod_inverse_composite_num_mod(value_type a, ll mod) {
  value_type x, y;
  extgcd(a, mod, x, y);
  return (mod + x % mod) % mod;
}
}
}
using namespace math::integer;
template <class T>
T lcm(T x, T y) {
  return x / __gcd(x, y) * y;
}

int main() {
  for (int A, B, d; cin >> A >> B >> d && (A | B | d);) {
    int G = __gcd(__gcd(A, B), d);
    A /= G, B /= G, d /= G;
    ll ans = 1e18, axby = 1e18;
    int tx = -1, ty = -1;
    for (int sgn = -1; sgn < 2; sgn += 2) {
      int a = sgn * A, b = -sgn * B;
      int x, y;
      int g = extgcd(a, b, x, y);
      x *= d / g, y *= d / g;
      ll L = lcm(a, b);
      rep(_, d) {
        if (x >= 0 || y >= 0) {
          if (minimize(ans, abs(x) + abs(y))) {
            axby = a * x + b * y;
            tx = x, ty = y;
          } else if (ans == abs(x) + abs(y)) {
            if (minimize(axby, (ll)a * x + b * y)) {
              tx = x, ty = y;
            }
          }
        }
        x += L / abs(a);
        y += L / abs(b);
      }
    }
    cout << abs(tx) << " " << abs(ty) << endl;
  }

  return 0;
}