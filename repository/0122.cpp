#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

pair<int, int> spr[10];

int dx[] = {-2, -2, -2, -1, 0, 1, 2, 2, 2, -1, 0, 1};
int dy[] = {-1, 0, 1, -2, -2, -2, -1, 0, 1, 2, 2, 2};

int sdx[] = {-1, 1, 0, 0, -1, 1, 1, -1, 0};
int sdy[] = {0, 0, -1, 1, -1, -1, 1, 1, 0};

using namespace std;

int N;
bool ans;

void solve(int const X, int const Y, int const SPRI) {
  if (ans) return;
  if (SPRI == N) {
    ans = 1;
    return;
  }

  for (int k = 0; k < 12; k++) {
    int npx = X + dx[k], npy = Y + dy[k];
    if (npx < 0 || npx > 9 || npy < 0 || npy > 9) continue;

    for (int kk = 0; kk < 9; kk++) {
      int const nsprx = spr[SPRI].first + sdx[kk];
      int const nspry = spr[SPRI].second + sdy[kk];
      if (nsprx < 0 || nsprx > 9 || nspry < 0 || nspry > 9) continue;

      if (npx == nsprx && npy == nspry) {
        solve(npx, npy, SPRI + 1);
      }
    }
  }
}

int main() {
  int sx, sy;

  while (cin >> sx >> sy && (sx | sy)) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> spr[i].first >> spr[i].second;
    }

    ans = 0;
    solve(sx, sy, 0);
    if (ans) {
      cout << "OK" << endl;
    } else {
      cout << "NA" << endl;
    }
  }

  return 0;
}