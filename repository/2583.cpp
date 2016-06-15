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

int N, maxw;

void solve(vector<string>& v) {
  auto get_top_plus = [&](int sy,
                          int x) {  // '+'????????????sy??\?????§????????????
    REP(y, sy, v.size()) {
      if (v[y][x] == '.' && isalpha(v[y][x + 1])) {
        return y;
      }
    }
    return -1;
  };

  auto find_down_through = [&](int sy, int& ty, int x) {
    REP(y, sy + 1, v.size()) {
      // '.'??§????????????????????¨(?¬????????????????????????¨???????????????)
      if (v[y][x] == '.' && isalpha(v[y][x + 1])) {
        ty = y;
        return true;
      } else if (v[y][x] != '.') {
        break;
      }
    }
    return false;
  };

  // ??????????????????????±????????????????????????????????????????+??§?§???????+??§?????????????????????????????????|??§?????????
  rep(x, maxw) {
    int y = 0;
    while (1) {
      y = get_top_plus(y, x);
      if (y == -1) {
        break;
      }
      v[y][x] = '+';
      int ny = -1;
      while (find_down_through(y, ny, x)) {
        v[ny][x] = '+';
        REP(i, y + 1, ny) { v[i][x] = '|'; }
        y = ny;
      }
      if (ny == -1) {
        y++;
      }
    }
  }

  rep(i, N) {
    for (int j = 0; !(j && isalpha(v[i][j - 1]) && v[i][j] == ' '); j++) {
      if (v[i][j] == '.')
        cout << ' ';
      else
        cout << v[i][j];
    }
    cout << endl;
  }
}

int main() {
  for (; cin >> N;) {
    vector<string> v(N);
    maxw = 0;
    rep(i, N) {
      cin >> v[i];
      maximize(maxw, v[i].size());
    }
    maxw++;
    rep(i, N) { v[i].resize(maxw, ' '); }
    solve(v);
  }

  return 0;
}