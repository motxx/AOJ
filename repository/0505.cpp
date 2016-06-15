#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  while (cin >> N >> M && (N | M)) {
    int vote[N][M];
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) cin >> vote[i][j];

    int sum[M];
    memset(sum, 0, sizeof sum);
    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++) sum[i] += vote[j][i];

    vector<pair<int, int> > vec(M);
    for (int i = 0; i < M; i++) vec[i] = make_pair(sum[i], -(i + 1));
    sort(vec.begin(), vec.end(), greater<pair<int, int> >());
    for (int i = 0; i < M; i++) {
      if (i) cout << ' ';
      cout << -vec[i].second;
    }
    cout << endl;
  }

  return 0;
}