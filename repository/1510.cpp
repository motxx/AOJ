#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

#define ck(x, a, b) (a <= x && x < b)

inline bool inrange(int x, int y, int z) {
  return ck(x, 0, 5) && ck(y, 0, 5) && ck(z, 0, 5);
}

int main() {
  for (int N, Tcnt = 1; cin >> N && N; Tcnt++) {
    vector<vector<vector<int> > > curr(5,
                                       vector<vector<int> >(5, vector<int>(5)));
    rep(z, 5) rep(y, 5) rep(x, 5) {
      char ch;
      cin >> ch;
      curr[z][y][x] = ch - '0';
    }

    int M1;
    cin >> M1;
    vector<int> a(M1);
    rep(i, M1) cin >> a[i];
    int M2;
    cin >> M2;
    vector<int> b(M2);
    rep(i, M2) cin >> b[i];

    rep(n, N) {
      vector<vector<vector<int> > > next(
          5, vector<vector<int> >(5, vector<int>(5)));
      rep(z, 5) rep(y, 5) rep(x, 5) {
        int cnt = 0;
        REP(dz, -1, 2) REP(dy, -1, 2) REP(dx, -1, 2) {
          int nx = x + dx, ny = y + dy, nz = z + dz;
          if (dx == 0 && dy == 0 && dz == 0) {
            continue;
          }
          if (!inrange(nx, ny, nz)) {
            continue;
          }
          cnt += curr[nz][ny][nx];
        }

        if (!curr[z][y][x]) {
          bool ok = 0;
          rep(I, M1) if (a[I] == cnt) {
            ok = 1;
            break;
          }
          if (ok) {
            next[z][y][x] = 1;
          }
        }

        if (curr[z][y][x]) {
          bool ok = 0;
          rep(I, M2) if (b[I] == cnt) {
            ok = 1;
            break;
          }
          if (ok) {
            next[z][y][x] = 1;
          }
        }
      }
      curr = next;
    }

    if (Tcnt > 1) cout << "\n";
    cout << "Case " << Tcnt << ":";
    rep(z, 5) {
      cout << endl;
      rep(y, 5) {
        rep(x, 5) cout << curr[z][y][x];
        cout << endl;
      }
    }
  }

  return 0;
}