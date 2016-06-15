#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int H, W;
int N, M;

int L, T;
int R, B;

int ans;

char F[65][65];
char c[65][65];

void get_rect() {
  L = 65, T = 65;
  R = 0, B = 0;

  rep(i, 65) rep(j, 65) {
    if (c[i][j] == '#') {
      T = min(T, i);
      L = min(L, j);
      B = max(B, i);
      R = max(R, j);
    }
  }
}

void solve() {
  char G[65][65];
  int ans_tmp;

  rep(k, N - B + T) rep(l, M - R + L) {  // oku hidari ue

    rep(i, N) rep(j, M) { G[i][j] = F[i][j]; }

    REP(i, T, B + 1) REP(j, L, R + 1) {  // c no hidari ue

      int pos_i = i - T, pos_j = j - L;  // small rect oku basyo

      if (G[k + pos_i][l + pos_j] == '#' && c[i][j] == '#') {
        goto Next;
      }

      if (c[i][j] == '#') {
        G[k + pos_i][l + pos_j] = '#';
      }
    }

    ans_tmp = 0;

    rep(i, N) {
      bool ok = 1;
      rep(j, M) {
        if (G[i][j] == '.') {
          ok = 0;
        }
      }
      ans_tmp += ok;
    }
    ans = max(ans, ans_tmp);
  Next:;
  }
}

int main() {
  int Tc;
  cin >> Tc;
  rep(_, Tc) {
    scanf("%d%d", &H, &W);
    rep(i, 65) rep(j, 65) c[i][j] = '.';
    rep(i, H) rep(j, W) cin >> c[i][j];
    scanf("%d%d", &N, &M);
    rep(i, N) rep(j, M) cin >> F[i][j];

    ans = -1;
    rep(t, 4) {
      char tmp[65][65];

      rep(i, 65) rep(j, 65) tmp[j][65 - 1 - i] = c[i][j];
      rep(i, 65) rep(j, 65) { c[i][j] = tmp[i][j]; }
      get_rect();
      solve();
    }

    cout << ans << endl;
  }

  return 0;
}