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

// INF
#define IINF (INT_MAX / 2)
#define INF (1 << 29)

// math
#define SQ(x) ((x) * (x))

// container utility
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define PB push_back
#define EACH(i, c) \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

// rep
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)

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

// dx, dy
int const dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int const dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// inRange
inline bool inRange(int x, int y, int W, int H) {
  return 0 <= x && x < W && 0 <= y && y < H;
}

// isPalindrome
inline bool isPalindrome(string s) {
  return equal(s.begin(), s.end(), s.rbegin());
}

ll cfront[100], cback[100];

ll memo[101][101];

ll dfs(int l, int r) {
  if (memo[l][r]) return memo[l][r];
  if (l + 1 == r) return 0;

  ll ret = INF;
  REP(m, l + 1, r) {
    ret = min(ret, dfs(l, m) + dfs(m, r) +
                       cfront[l] * cback[m - 1] * cfront[m] * cback[r - 1]);
  }

  return memo[l][r] = ret;
}

int main() {
  int N;
  cin >> N;
  rep(i, N) cin >> cfront[i] >> cback[i];
  cout << dfs(0, N) << endl;

  return 0;
}