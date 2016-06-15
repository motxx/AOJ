#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
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
#define watch(a) \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int const OppoSide = 0;
int const SameSide = 1;

int N;
vector<pair<int, int>> G[44444];
map<pair<int, int>, int> MP;
map<int, pair<int, int>> CD;
int vis[44444];

bool dfs(int curr, int col) {
  for (auto &e : G[curr]) {
    int next, dir;
    tie(next, dir) = e;
    int nextCol = dir == OppoSide ? col ^ 1 : col;
    if (vis[next] + 1) {
      if (vis[next] != nextCol) return false;
    } else {
      vis[next] = nextCol;
      if (!dfs(next, nextCol)) return false;
    }
  }
  return true;
}

int main() {
  for (int M; cin >> M && M;) {
    vector<int> xs, ys;
    vector<int> X, Y;
    vector<char> D;
    rep(i, M) {
      int x, y;
      char d;
      cin >> x >> y >> d;
      X.push_back(x), Y.push_back(y), D.push_back(d);

      xs.push_back(x - 1), ys.push_back(y - 1);
      xs.push_back(x), ys.push_back(y);
      xs.push_back(x + 1), ys.push_back(y + 1);

      if (d == 'x') {
        xs.push_back(x + 2);
      } else {
        ys.push_back(y + 2);
      }
    }

    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    sort(all(ys));
    ys.erase(unique(all(ys)), ys.end());

    vector<int> NX, NY;
    rep(i, X.size()) { NX.push_back(lower_bound(all(xs), X[i]) - X.begin()); }
    rep(i, Y.size()) { NY.push_back(lower_bound(all(ys), Y[i]) - Y.begin()); }
    X = NX, Y = NY;

    MP.clear(), CD.clear();
    rep(i, 44444) G[i].clear();
    N = 0;

    rep(i, X.size()) {
      MP[make_pair(Y[i], X[i])] = N;
      CD[N++] = make_pair(Y[i], X[i]);
      if (D[i] == 'x') {
        MP[make_pair(Y[i], X[i] + 1)] = N;
        CD[N] = make_pair(Y[i], X[i] + 1);
        G[N - 1].emplace_back(N, OppoSide), G[N].emplace_back(N - 1, OppoSide);
        N++;
      } else {
        MP[make_pair(Y[i] + 1, X[i])] = N;
        CD[N] = make_pair(Y[i] + 1, X[i]);
        G[N - 1].emplace_back(N, OppoSide), G[N].emplace_back(N - 1, OppoSide);
        N++;
      }
    }

    rep(i, N) {
      auto curr = CD[i];
      rep(k, 4) {
        auto next = make_pair(CD[i].first + dy[k], CD[i].second + dx[k]);
        if (MP.find(next) == MP.end())
          continue;  // ﾃ･ﾂｸﾂε･ﾂ崢｣ﾃ｣ﾂ??｣ﾂ?妥ｨﾂｪﾂｿﾃ｣ﾂ?ｹﾃ｣ﾂつ古｣ﾂ?ｰOK
        if (find(all(G[i]), make_pair(MP[next], OppoSide)) != G[i].end())
          continue;  // ﾃ･ﾂ按･ﾃ｣ﾂ?ｮﾃ･ﾂｸﾂε･ﾂ崢｣ﾃ｣ﾂ?ｯSameSideﾃ｣ﾂ?療｣ﾂ?凝･ﾂ?･ﾃ｣ﾂつ古｣ﾂつ暗｣ﾂ??｣ﾂ?ｨﾃ｣ﾂ?療｣ﾂ?ｪﾃ｣ﾂ??｣ﾂ?凝｣ﾂつ碓K
        G[i].emplace_back(MP[next], SameSide);
      }
    }

    minus(vis);

    bool ok = 1;

    rep(i, N) {
      if (vis[i] < 0) {
        vis[i] = 0;
        if (!dfs(i, 0)) {
          ok = 0;
          break;
        }
      }
    }

    cout << (ok ? "Yes" : "No") << endl;
  }
  return 0;
}