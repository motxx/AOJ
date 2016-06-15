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
bool isPrime(int a) {
  for (int i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}

int const dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int const dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

//////////////////////////////////////////////////////////////

int main() {
  int Tc;
  cin >> Tc;
  int grid[5][5];

  while (Tc--) {
    rep(i, 5) rep(j, 5) cin >> grid[i][j];
    int ans = 0;
    rep(i, 5) {
      rep(j, 5) {
        REP(k, i, 5) {
          REP(l, j, 5) {
            bool ok = true;
            REP(a, i, k + 1) {
              REP(b, j, l + 1) {
                if (grid[a][b] == 0) {
                  ok = false;
                  break;
                }
              }
              if (!ok) break;
            }
            if (ok) ans = max(ans, (k - i + 1) * (l - j + 1));
          }
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}