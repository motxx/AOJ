#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define fst first
#define snd second

int main() {
  int t, n;
  while (cin >> t >> n && (t | n)) {
    int M[200][200] = {};
    int const BX = 100, BY = 100;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      M[y + BY][x + BX] = 1;
    }

    int const dx[] = {-1, 1, 0, 0, 1, -1};
    int const dy[] = {0, 0, -1, 1, 1, -1};

    typedef pair<int, int> Pii;
    typedef pair<Pii, int> P;

    bool used[200][200] = {};
    int ans = 0;

    int sx, sy;
    cin >> sx >> sy;
    sx += BX, sy += BY;

    queue<P> Q;
    Q.push(P(Pii(sx, sy), t));
    used[sy][sx] = true;

    while (!Q.empty()) {
      P const p = Q.front();
      Q.pop();
      ans++;

      if (p.snd <= 0) continue;

      for (int i = 0; i < 6; i++) {
        int nx = p.fst.fst + dx[i], ny = p.fst.snd + dy[i];
        if (!used[ny][nx] && M[ny][nx] == 0) {
          Q.push(P(Pii(nx, ny), p.snd - 1));
          used[ny][nx] = true;
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}