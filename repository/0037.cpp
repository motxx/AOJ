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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

vector<pair<int, int>> G[55];

int main() {

  rep(i, 5) {
    char x;
    rep(j, 4) {
      cin >> x;
      if(x-'0') {
        G[i * 5 + j].emplace_back(i * 5 + j + 1, 2);
        G[i * 5 + j + 1].emplace_back(i * 5 + j, 0);
      }
    }

    if(i == 4) break;

    rep(j, 5) {
      cin >> x;
      if(x-'0') {
        G[i * 5 + j].emplace_back((i + 1) * 5 + j, 3);
        G[(i + 1) * 5 + j].emplace_back(i * 5 + j, 1);
      }
    }
  }

  string const OP = "LURD";

  int y = 0, x = 0, d = 2;

  while(y != 0 || x != 0 || d != 0) {
    int le = -1, st = -1, ri = -1, dw = -1;
    for(auto && e: G[y * 5 + x]) {
      if(e.second == (d + 3) % 4) le = e.second;
      if(e.second == (d + 1) % 4) ri = e.second;
      if(e.second == d) st = e.second;
      if(e.second == (d + 2) % 4) dw = e.second;
    }
    if(le != -1) d = le;
    else if(st != -1) ;
    else if(ri != -1) d = ri;
    else d = dw;
    y += dy[d], x += dx[d];
    cout << OP[d];
  }
  cout << endl;
    
  return 0;
}