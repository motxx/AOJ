#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF (1 << 29)

struct State {
  int to, cost;
  bool left;
  bool operator<(const State& s) const { return cost > s.cost; }
  State(int t, int c, bool l) : to(t), cost(c), left(l) {}
};

typedef pair<int, int> P;

vector<P> start, goal;
char t[61][31];
int G[61][31];
int W, H;

inline bool inF(int x, int y) { return 0 <= x && x < W && 0 <= y && y < H; }

/*
  0 1   2   3 ...
  W W+1 W+2 ...
  ...
*/
inline int nidx(int x, int y) { return y * W + x; }

inline int posx(int nidx) { return nidx % W; }

inline int posy(int nidx) { return nidx / W; }

inline bool isout(int i, int j) {
  if (i == -1 && j == 3) return true;
  if (i == +1 && j == 3) return true;
  if (i == -2 && j == 2) return true;
  if (i == +2 && j == 2) return true;
  if (i == -2 && j == 3) return true;
  if (i == +2 && j == 3) return true;
  return false;
}

int dijkstra() {
  int dist[61][31][2];
  fill(dist[0][0], dist[0][0] + 61 * 31 * 2, INF);
  priority_queue<State> PQ;
  for (int I = 0; I < start.size(); I++) {
    int sx = start[I].first, sy = start[I].second;
    dist[sy][sx][0] = dist[sy][sx][1] = 0;
    PQ.push(State(nidx(sx, sy), 0, false));
    PQ.push(State(nidx(sx, sy), 0, true));
  }
  while (!PQ.empty()) {
    const State st = PQ.top();
    PQ.pop();
    const int x = posx(st.to), y = posy(st.to);
    int s = st.left ? -1 : +1;

    if (t[y][x] == 'T') return st.cost;

    for (int i = -2; i <= 2; i++) {
      for (int j = 1; j <= 3; j++) {
        if (isout(i, j)) continue;
        int nx = x + s * j, ny = y + i;
        if (!inF(nx, ny)) continue;
        if (dist[ny][nx][!st.left] <= st.cost + G[ny][nx]) continue;
        dist[ny][nx][!st.left] = st.cost + G[ny][nx];
        PQ.push(State(nidx(nx, ny), dist[ny][nx][!st.left], !st.left));
      }
    }
  }

  return -1;
}

int main() {
  while (cin >> W >> H && (W | H)) {
    start.clear();
    goal.clear();
    for (int i = 0; i < H; i++)
      for (int j = 0; j < W; j++) {
        cin >> t[i][j];
        if (t[i][j] == 'S') {
          start.push_back(P(j, i));
          G[i][j] = 0;
        } else if (t[i][j] == 'T') {
          goal.push_back(P(j, i));
          G[i][j] = 0;
        } else if (t[i][j] == 'X') {
          G[i][j] = INF;
        } else {
          G[i][j] = t[i][j] - '0';
        }
      }

    cout << dijkstra() << endl;
  }

  return 0;
}