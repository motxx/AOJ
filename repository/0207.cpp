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

int const dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int const dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

//////////////////////////////////////////////////////////////

int main() {
  int W, H;
  while (cin >> W >> H && (W | H)) {
    int sx, sy, gx, gy, N;
    cin >> sx >> sy >> gx >> gy >> N;
    sx--, sy--, gx--, gy--;

    int grid[100][100] = {{}};

    for (int i = 0; i < N; i++) {
      int c, d, x, y;
      cin >> c >> d >> x >> y;
      x--, y--;

      grid[y][x] = grid[y + 1][x] = grid[y][x + 1] = grid[y + 1][x + 1] = c;
      if (!d) {
        grid[y][x + 2] = grid[y + 1][x + 2] = grid[y][x + 3] =
            grid[y + 1][x + 3] = c;
      } else {
        grid[y + 2][x] = grid[y + 2][x + 1] = grid[y + 3][x] =
            grid[y + 3][x + 1] = c;
      }
    }

    queue<PII> q;
    q.push(MP(sx, sy));

    int cost[100][100];
    fill(cost[0], cost[0] + 10000, -1);
    cost[sy][sx] = 0;

    while (!q.empty()) {
      PII pii = q.front();
      q.pop();
      int x = pii.FST, y = pii.SND;

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (CK(nx, 0, W) && CK(ny, 0, H) && cost[ny][nx] == -1 &&
            grid[sy][sx] == grid[ny][nx]) {
          q.push(PII(nx, ny));

          cost[ny][nx] = cost[y][x] + 1;
        }
      }
    }

    if (cost[gy][gx] == -1) {
      cout << "NG" << endl;
    } else {
      cout << "OK" << endl;
    }
  }

  return 0;
}