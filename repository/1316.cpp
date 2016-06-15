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

int H, W;
vector<string> F;

int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[8] = {0, -1, 0, 1, -1, -1, 1, 1};

unordered_map<string, int> mp;

void go(int y, int x, int dir, int sy, int sx) {
  string s;
  while (1) {
    s += F[y][x];
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if (ny >= H) {
      ny = 0;
    }
    if (ny < 0) {
      ny = H - 1;
    }
    if (nx >= W) {
      nx = 0;
    }
    if (nx < 0) {
      nx = W - 1;
    }
    if (ny == sy && nx == sx) {
      break;
    }
    y = ny, x = nx;
    mp[s]++;
  }
  mp[s]++;
}

int main() {
  for (; cin >> H >> W && (H | W);) {
    F.clear();
    rep(i, H) F.resize(H);
    vector<string> v;
    rep(i, H) cin >> F[i];
    mp.clear();
    rep(i, H) rep(j, W) {
      rep(k, 8) { go(i, j, k, i, j); }
    }

    vector<string> u;
    for (auto&& e : mp) {
      if (e.first.size() > 1 && e.second > 1) {
        u.push_back(e.first);
      }
    }

    if (u.empty()) {
      cout << 0 << endl;
    } else {
      sort(all(u), [&](string const& s, string const& t) {
        int n = s.size(), m = t.size();
        return n != m ? n > m : s < t;
      });
      cout << u[0] << endl;
    }
  }

  return 0;
}