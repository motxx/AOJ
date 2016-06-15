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

int N, M;
string s[100];
int val[100];

int check(string t) {
  rep(i, N) {
    int const SIZE = t.size();
    bool ok = 1;
    rep(j, SIZE) { ok = ok && (s[i][j] == '*' || s[i][j] == t[j]); }
    if (ok) {
      return val[i];
    }
  }

  return 0;
}

int main() {
  while (cin >> N >> M) {
    if (N == 0) return 0;
    rep(i, N) { cin >> s[i] >> val[i]; }

    int sum = 0;
    rep(i, M) {
      string t;
      cin >> t;
      sum += check(t);
    }

    cout << sum << endl;
  }

  return 0;
}