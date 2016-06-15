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

int const MAX_M = 31;
int const MAX_N = 9;

double edge[MAX_M][MAX_M];
double dp[MAX_M][1 << MAX_N];

int main() {
  int N, M, P, S, T;
  while (cin >> N >> M >> P >> S >> T) {
    if (!(N | M | P | S | T)) break;
    S--;
    T--;
    fill(edge[0], edge[MAX_M], INF);

    double tickets[N];
    rep(i, N) cin >> tickets[i];

    rep(i, P) {
      int a, b, c;
      cin >> a >> b >> c;
      a--, b--;
      edge[a][b] = edge[b][a] = c;
    }

    fill(dp[0], dp[MAX_M], INF);
    dp[S][0] = 0;

    for (int stT = 0; stT < (1 << N); stT++) {
      for (int u = 0; u < M; u++) {
        for (int i = 0; i < N; i++) {
          if (stT & (1 << i)) continue;
          for (int v = 0; v < M; v++) {
            if (edge[u][v] == INF) continue;
            dp[v][stT | (1 << i)] = min(dp[v][stT | (1 << i)],
                                        dp[u][stT] + edge[u][v] / tickets[i]);
          }
        }
      }
    }

    double ans = *min_element(dp[T], dp[T + 1]);
    if (ans == INF) {
      cout << "Impossible" << endl;
    } else {
      printf("%.3f\n", ans);
    }
  }

  return 0;
}