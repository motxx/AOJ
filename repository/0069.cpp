#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)

int m, k, a, d;
vector<string> g;

bool solve() {
  int x = k - 1;
  rep(y, d) {
    if(g[y][x]) x++;
    else if(x && g[y][x-1]) x--;
  }
  return x == a - 1;
}

int main() {

  while(cin >> m >> k >> a >> d && m) {
    g.clear(); g.resize(d);
    rep(i, d) cin >> g[i];
    rep(i, d) for(auto& e: g[i]) e -= '0';
    if(solve()) {
      cout << "0\n";
      goto next;
    }
    rep(i, d) rep(j, m - 1) {
      if(!g[i][j] && (j == 0 || !g[i][j-1]) && (j + 1 == m - 1 || !g[i][j+1])) {
        g[i][j] = 1;
        if(solve()) {
          cout << i + 1 << " " << j + 1 << endl;
          goto next;
        }
        g[i][j] = 0;
      }
    }
    cout << "1\n";
  next:;
  }
  
  return 0;
}