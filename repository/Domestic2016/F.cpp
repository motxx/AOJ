#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int dx[8] = {-1,0,1,0,-1,1,1,-1};
int dy[8] = {0,-1,0,1,-1,-1,1,1};

template<class T> constexpr bool in_range(T y, T x, T H, T W) { return 0<=y&&y<H&&0<=x&&x<W; }

struct union_find {
  vector<int> rank_, rid_;
  union_find(int n) { rank_.resize(n); rid_.assign(n, -1); };
  void operator()(int u, int v) {
    u = operator[](u), v = operator[](v);
    if(u == v) { return; }
    if(rank_[u] < rank_[v]) { rid_[u] = v; }
    else { rid_[v] = u; if(rank_[u] == rank_[v]) { rank_[u]++; } }    
  }
  int operator[](int x) { if(rid_[x] < 0) return x; else return rid_[x] = operator[](rid_[x]); }
};

namespace tree {

using tree_type = vector<vector<int>>;

std::string to_string(tree_type const& t, int v, int par = -1) {
  ostringstream oss;
  oss << '(';
  vector<string> children;
  children.resize(t[v].size());
  for(int u: t[v]) {
    if(u == par) continue;
    children.emplace_back(to_string(t, u, v));
  }
  sort(children.begin(), children.end());
  for(auto const& child: children)
    oss << child;
  oss << ')';
  return oss.str();
}

bool tree_isomorphism(tree_type const& a, tree_type const& b) {
  return to_string(a, 0) == to_string(b, 0);
}

}

int H, W;
vector<string> G;
vector<vector<bool>> vis;
vector<vector<int>> T[2];

vector<pair<int, int>> erase_bfs(int y, int x, int outer, map<int, int>& mp, union_find& uf) {
  vector<pair<int, int>> ret;
  queue<pair<int, int>> q;
  q.push({y, x});
  vis[y][x] = 1;

  set<int> st = {outer};

  while(!q.empty()) {
    int y, x; tie(y, x) = q.front(); q.pop();
    rep(k, 8) {
      int ny = y + dy[k], nx = x + dx[k];
      if(!in_range(ny, nx, H, W)) continue;
      if(vis[ny][nx]) continue;
      if(G[ny][nx] == '#') {
        vis[ny][nx] = 1;
        q.push({ny, nx});
      } else {
        if(st.count(mp[uf[ny * W + nx]])) continue;
        st.insert(mp[uf[ny * W + nx]]);
        ret.emplace_back(ny, nx);
      }
    }
  }

  return ret;
}

void make_tree(vector<vector<int>>& T) {

  union_find uf(H * W + 10);

  rep(i, H) rep(j, W) {
    rep(k, 4) {
      int ni = i + dy[k], nj = j + dx[k];
      if(!in_range(ni, nj, H, W)) continue;
      if(G[i][j] == '.' && G[ni][nj] == '.') {
        uf(i * W + j, ni * W + nj);
      }
    }
    rep(k, 8) {
      int ni = i + dy[k], nj = j + dx[k];
      if(!in_range(ni, nj, H, W)) continue;
      if(G[i][j] == '#' && G[ni][nj] == '#') {
        uf(i * W + j, ni * W + nj);
      }
    }
  }

  map<int, int> mp;
  int K = 0;
  rep(i, H) rep(j, W) {
    if(mp.find(uf[i * W + j]) == mp.end())
      mp[uf[i * W + j]] = K ++;
  }

  T.clear();
  T.resize(K);

  queue<pair<int, int>> q;

  vis.clear(); vis.resize(H); rep(i, H) vis[i].resize(W);
  q.emplace(0, 0);
  vis[0][0] = 0;

  while(!q.empty()) {
    auto p = q.front(); q.pop();
    int y, x; tie(y, x) = p;

    rep(k, 4) {
      int ny = y + dy[k], nx = x + dx[k];
      if(!in_range(ny, nx, H, W)) continue;
      if(vis[ny][nx]) continue;
      vis[ny][nx] = 1;
      if(G[ny][nx] == '#') {
        int id = mp[uf[y * W + x]];
        int nid = mp[uf[ny * W + nx]];
        auto v = erase_bfs(ny, nx, id, mp, uf);
        T[id].push_back(nid);
        T[nid].push_back(id);
        for(auto r: v) {
          vis[r.first][r.second] = 1;
          int nxnid = mp[uf[r.first * W + r.second]];
          T[nid].push_back(nxnid);
          T[nxnid].push_back(nid);
          q.emplace(r.first, r.second);
        }
      }
      else {
        q.emplace(ny, nx);
      }
    }
  }
}

namespace graph::visualizer {

using graph_type = vector<vector<int>>;

void directed_graph(graph_type& g, const string fname = "digraph") {
  const string gfname = "__graph_vis_out_" + fname + ".dot";
  ofstream ofs(gfname);
  ofs << "digraph {" << endl;
  rep(i, g.size()) rep(k, g[i].size()) {
    ofs << i << " -> " << g[i][k] << ";" << endl;
  }
  ofs << "}" << endl;
  ofs.close();
  int r = system(("dot -Tpng " + gfname + " > " + fname + ".png").c_str());
  if(!WEXITSTATUS(r)) {
    r = system(("rm " + gfname).c_str());
    if(!WEXITSTATUS(r)) {
//      r = system(("open " + fname + ".png").c_str()); assert(!r && "open error");
    } else assert(0 && "rm error");
  } else assert(0 && "dot error");
}

}

bool input_grid() {
  cin >> H >> W;
  if((H|W) == 0) return false;
  H += 2, W += 2;
  G.clear();
  G.resize(H);
  rep(i, H) G[i].resize(W);
  rep(i, H) rep(j, W) G[i][j] = '.';
  REP(i, 1, H - 1) REP(j, 1, W - 1) cin >> G[i][j];
  return true;
}

int main() {

  while(1) {
    static int tcnt = 0; tcnt ++;
    if(!input_grid()) break;
    make_tree(T[0]);
    #if 0
      rep(i, H) cout << G[i] << endl; cout << endl;
      graph::visualizer::directed_graph(T[0], "dg-1");
    #endif
    input_grid();
    make_tree(T[1]);
    #if 0
      rep(i, H) cout << G[i] << endl; cout << endl;
      graph::visualizer::directed_graph(T[1], "dg-2");
    #endif
    string s, t;
    cout << (tree::tree_isomorphism(T[0], T[1]) ? "yes\n" : "no\n");
  }

  return 0;
}