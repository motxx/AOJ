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

int M[120][120];
int G[4][30][30];

int main() {
  int n, m;

  while (cin >> n >> m && (n | m)) {
    rep(i, n) rep(j, n) cin >> M[i][j];
    rep(i, m) rep(j, m) cin >> G[0][i][j];

    rep(k, 3) rep(i, m) rep(j, m) G[k + 1][m - 1 - j][i] = G[k][i][j];

    VII data;

    rep(k, 4) {
      int ax = INF, ay;
      rep(i, m) {
        rep(j, m) {
          if (G[k][i][j] != -1) {
            ax = j, ay = i;
            break;
          }
        }
        if (ax != INF) {
          break;
        }
      }
      data.PB(PII(ax, ay));
    }

    int ax = INF, ay = INF;

    rep(i, n - m + 1) {
      rep(j, n - m + 1) {
        rep(k, 4) {
          bool ok = 1;

          rep(a, m) {
            rep(b, m) {
              if (G[k][a][b] == -1) {
                continue;
              }
              if (G[k][a][b] != M[i + a][j + b]) {
                ok = 0;
                break;
              }
            }
            if (!ok) {
              break;
            }
          }

          if (!ok) continue;

          if (ay > i + data[k].SND) {
            ax = j + data[k].FST, ay = i + data[k].SND;
          } else if (ay == i + data[k].SND) {
            if (ax > j + data[k].FST) {
              ax = j + data[k].FST;
            }
          }
        }
      }
    }

    if (ax == INF) {
      cout << "NA" << endl;
    } else {
      cout << ax + 1 << ' ' << ay + 1 << endl;
    }
  }

  return 0;
}