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
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

int p, q;

int main() {
  for (int N, Q; cin >> N >> Q && (N | Q);) {
    vector<string> M(N);
    vector<string> T(Q);
    vector<int> ans(Q);
    rep(i, Q) ans[i] = inf;
    rep(i, N) cin >> M[i];
    rep(i, Q) cin >> T[i];
    REP(R, 1, 21) REP(C, 1, 21) REP(S, 1, 21) {
      bool ok = 1;
      int r = 0, c = 0, s = 0;
      rep(i, N) {
        const int MiLen = M[i].size();
        int indent = 0;
        rep(j, MiLen) {
          if (M[i][j] == '.') {
            indent++;
          } else {
            if (R * r + C * c + S * s != indent) {
              ok = 0;
            }
            break;
          }
        }
        rep(j, MiLen) {
          r += (M[i][j] == '(') - (M[i][j] == ')');
          c += (M[i][j] == '{') - (M[i][j] == '}');
          s += (M[i][j] == '[') - (M[i][j] == ']');
        }
      }

      if (!ok) {
        continue;
      }

      r = 0, c = 0, s = 0;

      rep(i, Q) {
        if (ans[i] == inf) {
          ans[i] = R * r + C * c + S * s;
        } else if (ans[i] != R * r + C * c + S * s) {
          ans[i] = -1;
        }

        int n = T[i].size();
        rep(j, n) {
          r += (T[i][j] == '(') - (T[i][j] == ')');
          c += (T[i][j] == '{') - (T[i][j] == '}');
          s += (T[i][j] == '[') - (T[i][j] == ']');
        }
      }
    }

    rep(i, Q) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}