#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<pair<int, int> > VII;

int main() {
  const int TS = 530, TE = 1270;
  const int SPAN = TE - TS;
  int N, M;
  while (cin >> N >> M, N) {
    int r;
    cin >> r;
    VVI dat(M, VI(SPAN, 0));
    for (int i = 0; i < r; i++) {
      int t, n, m, s;
      cin >> t >> n >> m >> s;
      m--;
      t -= TS;
      if (s)
        dat[m][t]++;
      else
        dat[m][t]--;
    }

    for (int i = 0; i < M; i++) {
      // imos PCs login: 1 logout: -1
      for (int j = 0; j < SPAN; j++) {
        dat[i][j + 1] += dat[i][j];
      }
    }

    VVI dat2(M, VI(SPAN, 0));

    for (int i = 0; i < M; i++) {
      // 複数のPCをひとまとめにして、更に時間の累積和を取る
      for (int j = 0; j < SPAN; j++) {
        dat2[i][j + 1] = dat2[i][j] + (dat[i][j] > 0);
      }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      int ts, te, m;
      cin >> ts >> te >> m;
      m--;
      ts -= TS;
      te -= TS;
      cout << dat2[m][te] - dat2[m][ts] << endl;
    }
  }

  return 0;
}