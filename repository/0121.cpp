#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
using namespace std;

map<string, int> mp;
set<string> st;

#define ALL(c) ((c).begin, (c).end())
#define MP make_pair

int solve() {
  string s;
  for (int i = 0; i < 8; i++) {
    int x;
    if (scanf("%d", &x) == EOF) return -1;
    s += (char)(x + '0');
  }

  return mp[s];
}

int main() {
  int const dir[] = {-1, -4, 1, 4};

  typedef pair<int, string> State;

  queue<State> q;
  q.push(MP(0, "01234567"));
  st.insert("01234567");
  while (!q.empty()) {
    const int cost = q.front().first;
    const string s = q.front().second;
    q.pop();

    int pos = s.find('0');

    for (int i = 0; i < 4; i++) {
      int npos = pos + dir[i];
      if (dir[i] == 1 && npos == 4) continue;
      if (dir[i] == -1 && npos == 3) continue;
      if (npos < 0 || npos > 7) continue;

      string ns = s;
      swap(ns[pos], ns[npos]);
      int ncost = cost + 1;
      if (st.count(ns) && mp[ns] < ncost) continue;
      mp[ns] = ncost;
      st.insert(ns);
      q.push(MP(ncost, ns));
    }
  }

  while (1) {
    int ret = solve();
    if (ret == -1)
      break;
    else {
      cout << ret << endl;
    }
  }

  return 0;
}