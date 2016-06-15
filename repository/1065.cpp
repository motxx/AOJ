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

// !!! set MAX_L number !!!
#define MAX_L (1000001)
#define MAX_SQRT_B ((int)sqrt(INT_MAX) + 1)

bool is_prime[MAX_L];
vector<bool> is_prime_small(MAX_SQRT_B);

void segment_sieve(ll a, ll b) {
  for (int i = 0; (ll)i * i < b; i++) is_prime_small[i] = true;
  for (int i = 0; i < b - a; i++) is_prime[i] = true;

  if (a == 1) {
    is_prime[0] = false;
  }

  is_prime_small[0] = is_prime_small[1] = false;

  for (int i = 2; (ll)i * i < b; i++) {
    if (is_prime_small[i]) {
      for (int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
      for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
        is_prime[j - a] = false;
    }
  }
}

//////////////////////////////////////////////////////////////

struct Edge {
  int to, cost, id;
  Edge(int t, int c, int i) : to(t), cost(c), id(i) {}
};

#define MAX_E (198)

vector<Edge> es[MAX_E];
int N, M;

bool isConnected(int x) {
  vector<bool> used(N);
  vector<int> VEC;
  VEC.PB(0);
  used[0] = 1;

  int v = 0;
  while (!VEC.empty()) {
    vector<int> NEXT;

    EACH(i, VEC) {
      EACH(e, es[*i]) {
        if (e->id != x && !used[e->to]) {
          used[e->to] = 1;
          NEXT.PB(e->to);
        }
      }
      v++;
    }
    VEC = NEXT;
  }
  return N == v;
}

int main() {
  while (cin >> N >> M && (N | M)) {
    for (int i = 0; i < MAX_E; i++) {
      es[i].clear();
    }

    int base = 0;
    int id = 0;

    vector<int> cost;

    for (int i = 0; i < M; i++) {
      int s, t, c;
      cin >> s >> t >> c;

      if (c <= 0)
        base += c;
      else {
        es[s].PB(Edge(t, c, id));
        es[t].PB(Edge(s, c, id));
        cost.PB(c);
        id++;
      }
    }

    int E = id;
    int ans = INF;

    if (!isConnected(-1)) ans = 0;

    for (int i = 0; i < E; i++) {
      if (!isConnected(i)) ans = min(ans, cost[i]);
    }

    for (int i = 0; i < E - 1; i++)
      for (int j = i + 1; j < E; j++) ans = min(ans, cost[i] + cost[j]);

    cout << base + ans << endl;
  }

  return 0;
}