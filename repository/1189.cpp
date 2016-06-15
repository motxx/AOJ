#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define MP make_pair
#define PB push_back
#define MAX_N 1010000
#define SIZE 3000
#define X first
#define Y second

const int STX = 1500, STY = 1500;

typedef pair<int, int> Pii;
typedef pair<int, Pii> P;

int id[SIZE][SIZE];
bool is_prime[MAX_N + 1];
vector<Pii> coord;

void Sieve() {
  fill(is_prime, is_prime + MAX_N + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= MAX_N; i++)
    if (is_prime[i])
      for (int j = i * i; j <= MAX_N; j += i) is_prime[j] = false;
}

void MakeMap() {
  int x = STX, y = STY;
  int cnt = 0;

  coord.PB(MP(0, 0));  // no use
  cnt++;
  coord.PB(MP(x, y));  // cnt = 1

  fill(id[0], id[0] + SIZE * SIZE + 1, -1);

  const int dx[] = {0, -1, 0, 1};
  const int dy[] = {-1, 0, 1, 0};

  int a = 0;
  x = STX + 1;
  y = STY + 1;
  while (cnt <= MAX_N) {
    a += 2;
    for (int turn = 0; turn < 4; turn++) {
      for (int i = 0; i < a; i++) {
        x += dx[turn], y += dy[turn];
        coord.PB(MP(x, y));
        id[y][x] = ++cnt;
      }
    }
    x++, y++;
  }
}

int dp[MAX_N + 1];

int main() {
  Sieve();
  MakeMap();

  int m, n;

  while (cin >> m >> n && (m | n)) {
    fill(dp, dp + MAX_N + 1, -1);
    dp[n] = is_prime[n];
    Pii ans(dp[n], n);

    queue<P> que;
    que.push(P(dp[n], coord[n]));
    while (!que.empty()) {
      P now = que.front();
      que.pop();
      int tmpid = id[now.second.Y][now.second.X];
      if (now.first < dp[tmpid]) continue;

      int noid = id[now.second.Y][now.second.X];

      for (int i = -1; i <= 1; i++) {
        Pii nex = MP(now.second.X + i, now.second.Y + 1);
        if (nex.X < 0 || SIZE <= nex.X || nex.Y < 0 || SIZE <= nex.Y) continue;
        int neid = id[nex.Y][nex.X];
        if (neid <= m) {
          if (dp[neid] < dp[noid] + is_prime[neid]) {
            dp[neid] = dp[noid] + is_prime[neid];
            if (is_prime[neid]) ans = max(ans, MP(dp[neid], neid));
            que.push(P(dp[neid], nex));
          }
        }
      }
    }

    if (ans.first == 0)
      cout << "0 0" << endl;
    else
      cout << ans.first << ' ' << ans.second << endl;
  }
  return 0;
}