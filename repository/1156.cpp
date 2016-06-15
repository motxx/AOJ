#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int SIZE = 31;
const int INF = 1 << 27;

int G[SIZE][SIZE], C[4];
int H, W;

class State {
 public:
  int x, y, d, cost;
  State() {}
  State(int x, int y, int d, int cost) : x(x), y(y), d(d), cost(cost) {}
  bool operator<(const State &s) const { return cost > s.cost; }
};

int solve() {
  int cost[4][SIZE][SIZE];
  priority_queue<State> pq;
  pq.push(State(0, 0, 0, 0));
  fill(cost[0][0], cost[4][0], INF);
  cost[0][0][0] = 0;
  while (!pq.empty()) {
    const State s = pq.top();
    pq.pop();
    if (s.x == W - 1 && s.y == H - 1) return s.cost;
    for (int i = 0; i < 4; i++) {
      State t = s;
      t.cost += (G[s.y][s.x] == i ? 0 : C[i]);
      t.d = (s.d + i) % 4;
      t.x += dx[t.d], t.y += dy[t.d];
      if (0 <= t.x && t.x < W && 0 <= t.y && t.y < H &&
          cost[t.d][t.y][t.x] > t.cost) {
        pq.push(t);
        cost[t.d][t.y][t.x] = t.cost;
      }
    }
  }

  return INF;
}

int main() {
  while (cin >> W >> H, W + H) {
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) cin >> G[i][j];

    for (int i = 0; i < 4; i++) cin >> C[i];

    cout << solve() << endl;
  }

  return 0;
}