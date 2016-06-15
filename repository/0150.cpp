#include <bits/stdc++.h>
using namespace std;

// infty
#define ULLINF (ULLONG_MAX)
#define LLINF (LLONG_MAX)
#define IINF (INT_MAX)
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

// typedef
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef vector<VI> VVI;

typedef long long ll;

// pair util
#define FST first
#define SND second

// range validator
#define CK(n, a, b) (a <= n && n < b)

// conversion
template <class T>
inline string toStr(T a) {
  ostringstream oss_;
  oss_ << a;
  return oss_.str();
}
inline int toInt(string s) { return atoi(s.c_str()); }

// prime
int isp[10000000];
bool isPrime(int a) {
  if (a == 1) return isp[a] = 0;

  if (isp[a] >= 0) return isp[a];
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return isp[a] = 0;

  return isp[a] = 1;
}

int const dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int const dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

//////////////////////////////////////////////////////////////

int main() {
  memset(isp, -1, sizeof(isp));

  int n;
  while (cin >> n && n) {
    int ans = -INF;
    for (int i = 5; i <= n; i++) {
      if (isPrime(i - 2) && isPrime(i)) {
        ans = max(ans, i);
      }
    }
    cout << ans - 2 << ' ' << ans << endl;
  }

  return 0;
}