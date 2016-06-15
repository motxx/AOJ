#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define pb push_back
#define MP make_pair
#define MAX_N 1000
#define all(c) (c).begin(), (c).end()
#define ck(a, b) (0 <= (a) && (a) < (b))

int W, H, N;
int X1[MAX_N], Y1[MAX_N], X2[MAX_N], Y2[MAX_N];

int compress(int *x1, int *x2, int w) {
  vector<int> xs;

  for (int i = 0; i < N; i++) {
    for (int j = -1; j <= 1; j++) {
      int tx1 = x1[i] + j, tx2 = x2[i] + j;
      if (0 <= tx1 && tx1 < w) xs.pb(tx1);
      if (0 <= tx2 && tx2 < w) xs.pb(tx2);
    }
  }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  for (int i = 0; i < N; i++) {
    x1[i] = lower_bound(all(xs), x1[i]) - xs.begin();
    x2[i] = lower_bound(all(xs), x2[i]) - xs.begin();
  }

  return xs.size();
}

void Fill(vector<vector<bool> > &mp, int x1, int y1, int x2, int y2) {
  for (int i = y1; i < y2; i++)
    for (int j = x1; j < x2; j++) mp[i][j] = 1;
}

void bfs(vector<vector<bool> > &mp, int i, int j, int h, int w) {
  const int dx[] = {-1, 1, 0, 0};
  const int dy[] = {0, 0, -1, 1};
  typedef pair<int, int> PII;
  queue<PII> q;
  q.push(MP(i, j));

  while (!q.empty()) {
    const PII no = q.front();
    q.pop();

    if (!mp[no.first][no.second]) {
      mp[no.first][no.second] = 1;

      for (int k = 0; k < 4; k++) {
        PII nx = no;
        nx.first += dy[k];
        nx.second += dx[k];
        if (ck(nx.first, h) && ck(nx.second, w)) q.push(nx);
      }
    }
  }
}

int main() {
  while (cin >> W >> H, (W | H)) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    int w = compress(X1, X2, W);
    int h = compress(Y1, Y2, H);

    vector<vector<bool> > M(h, vector<bool>(w, 0));
    for (int i = 0; i < N; i++) Fill(M, X1[i], Y1[i], X2[i], Y2[i]);

    int ans = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!M[i][j]) {
          ans++;
          bfs(M, i, j, h, w);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}