#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define INF (1 << 29)

// math
#define Sq(x) ((x) * (x))

// container utility
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PB push_back
#define EACH(it, c) \
  for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

// rep
#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

// debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x)                                         \
  cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
       << " " << __FILE__ << endl;

// typedef
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;

typedef long long ll;

// useful
#define FST first
#define SND second

#define CK(n, a, b) (a <= n && n < b)

// conversion
template <class T>
inline string toStr(T a) {
  ostringstream oss;
  oss << a;
  return oss.str();
}
inline int toInt(string s) { return atoi(s.c_str()); }

// prime
bool isPrime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}

// !!! set SSIEVVE_MAX_L number !!!
#define SSIEVE_MAX_L (1000001)
#define SSIEVE_MAX_SQRT_B ((int)sqrt(INT_MAX) + 1)

bool is_prime[SSIEVE_MAX_L];
vector<bool> is_prime_small(SSIEVE_MAX_SQRT_B);

void segment_sieve(ll a, ll b) {
  for (int i = 0; (ll)i * i < b; i++) is_prime_small[i] = true;
  for (int i = 0; i < b - a; i++) is_prime[i] = true;

  if (a == 1) {
    is_prime[0] = false;
  }

  for (int i = 2; (ll)i * i < b; i++) {
    if (is_prime_small[i]) {
      for (int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
      for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
        is_prime[j - a] = false;
    }
  }
}

int const dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int const dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

//////////////////////////////////////////////////////////////

int main() {
  int N, M;
  int tcase = 1;

  while (cin >> N >> M && (N | M)) {
    VI next(22), now(22);

    /*
    for(int i=0; i<N/2; i++) {
      next[0] = ++ now[0], next[1] = ++ now[1];
    }
    if(N % 2) next[0] = ++ now[0];
    */

    now[0] = N;

    int ans = 0;
    while (now[M] == 0) {
      fill(ALL(next), 0);
      for (int i = 0; i < 22; i++) {
        next[i + 1] += now[i] / 2;
        next[0] += now[i] / 2;
        next[i] += now[i] % 2;
      }
      ans++;

      /*
        for(int i=0; i<22; i++) now[i] = next[i];
      */

      now.swap(next);
    }

    cout << "Case " << tcase++ << ": " << ans << endl;
  }

  return 0;
}