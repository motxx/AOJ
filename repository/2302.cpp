#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()

typedef pair<int, int> pii;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template <class T> constexpr bool in_range(T y, T x, T H, T W) {
  return 0 <= y && y < H && 0 <= x && x < W;
}

struct consumption {
  int on, off, stay;
  consumption() {}
  consumption(int on, int off, int stay) : on(on), off(off), stay(stay) {}
};

/*------------------------------------------*/
int H, W, M;
vector<string> G;
map<pii, consumption> costs;
vector<pii> vs;
map<pii, int> cnt;
/*------------------------------------------*/

int bfs(pii s, pii t) {

  map<pii, int> dist;
  dist[s] = 0;

  queue<pii> q;
  q.push(s);

  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();
    if (y == t.first && x == t.second)
      return dist[{y, x}];
    rep(k, 4) {
      int ny = y + dy[k], nx = x + dx[k];
      if (!in_range(ny, nx, H, W))
        continue;
      if (G[ny][nx] == '#')
        continue;
      if (dist.find({ny, nx}) == dist.end()) {
        dist[{ny, nx}] = dist[{y, x}] + 1;
        q.push({ny, nx});
      }
    }
  }
  assert(0);
}

vector<pii> make_path() {
  vector<pii> path = {vs[0]};
  queue<pii> q;
  q.push(vs[0]);
  set<pii> vis;
  vis.insert(vs[0]);
  pii prev[55][55];
  int idx = 0;

  while (!q.empty()) {
    int y, x;
    tie(y, x) = q.front();
    q.pop();
    if (idx + 1 >= vs.size())
      continue;
    if (y == vs[idx + 1].first && x == vs[idx + 1].second) {
      vector<pii> pt;
      pii curr = vs[idx + 1];
      for (; curr != vs[idx]; curr = prev[curr.first][curr.second])
        pt.push_back(curr);
      reverse(all(pt));
      for (auto &e : pt)
        path.push_back(e);
      idx++;
      if (idx == vs.size())
        break;
      vis.clear();
      vis.insert({y, x});
      while (!q.empty())
        q.pop();
    }
    rep(k, 4) {
      int ny = y + dy[k], nx = x + dx[k];
      if (!in_range(ny, nx, H, W))
        continue;
      if (G[ny][nx] == '#')
        continue;
      if (vis.count({ny, nx}))
        continue;
      vis.insert({ny, nx});
      prev[ny][nx] = {y, x};
      q.push({ny, nx});
    }
  }
  return path;
}

void input() {
  cin >> H >> W >> M;
  G.resize(H);
  rep(i, H) cin >> G[i];

  int C[3][H][W];
  rep(k, 3) rep(i, H) rep(j, W) cin >> C[k][i][j];
  rep(i, H) rep(j, W) costs[{i, j}] = {C[1][i][j], C[2][i][j], C[0][i][j]};
  rep(i, M) {
    int r, c;
    cin >> r >> c;
    vs.emplace_back(r, c);
  }
}

int main() {

  input();

  auto path = make_path();
  for (auto e : path)
    cnt[e]++;

  int ans = 0;
  map<pii, int> dist;
  int currdist = 0;
  pii prev = vs[0];

  for (auto &&e : path) {
    currdist += bfs(prev, e);
    if (dist.find(e) == dist.end())
      ans += costs[e].on;
    else
      ans +=
          min(costs[e].off + costs[e].on, costs[e].stay * (currdist - dist[e]));
    if (cnt[e] == 1)
      ans += costs[e].off;
    cnt[e]--;
    dist[e] = currdist;
    prev = e;
  }

  cout << ans << endl;

  return 0;
}