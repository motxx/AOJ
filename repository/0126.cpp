#include <bits/stdc++.h>
using namespace std;
// rep
#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

typedef pair<int, int> PII;
typedef vector<PII> VII;
int main() {
  int N;
  bool blank = 0;
  cin >> N;
  rep(_, N) {
    if (blank) cout << endl;
    blank = 1;
    int arr[9][9] = {{}};
    char output[9][20] = {{}};
    VII star;
    rep(i, 9) {
      int used[10] = {};
      rep(j, 9) {
        cin >> arr[i][j];
        used[arr[i][j]]++;
        output[i][2 * j] = ' ';
        output[i][2 * j + 1] = (char)('0' + arr[i][j]);
      }
    }

    rep(i, 9) {
      int used[10] = {};
      rep(j, 9) used[arr[i][j]]++;
      rep(j, 9) if (used[arr[i][j]] > 1) output[i][2 * j] = '*';
    }

    rep(j, 9) {
      int used[10] = {};
      rep(i, 9) used[arr[i][j]]++;
      rep(i, 9) if (used[arr[i][j]] > 1) output[i][2 * j] = '*';
    }

    rep(i, 3) {
      rep(j, 3) {
        int used[10] = {};
        rep(k, 3) rep(l, 3) used[arr[i * 3 + k][j * 3 + l]]++;
        rep(k, 3) rep(l, 3) if (used[arr[i * 3 + k][j * 3 + l]] > 1)
            output[(i * 3 + k)][2 * (j * 3 + l)] = '*';
      }
    }

    rep(i, 9) cout << output[i] << endl;
  }

  return 0;
}