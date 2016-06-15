#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

string initial, target;
vector<pair<string, string>> subs;

int dodo() {
  set<string> used;
  queue<pair<string, int>> q;
  q.emplace(initial, 0);
  while (!q.empty()) {
    string p;
    int cost;
    tie(p, cost) = q.front();
    q.pop();
    int n = p.size();
    if (p == target) {
      return cost;
    }
    rep(k, subs.size()) {
      string np;
      int pos = 0;
      int m1 = subs[k].first.size();
      if (n < m1) {
        continue;
      }
      while (pos < n) {
        int nxtpos = p.find(subs[k].first, pos);
        if (nxtpos == string::npos) {
          np += p.substr(pos);
          break;
        }
        np += string(p.begin() + pos, p.begin() + nxtpos) + subs[k].second;
        pos = nxtpos + m1;
      }
      if (np.size() > target.size()) {
        continue;
      }
      if (used.count(np)) {
        continue;
      }
      used.insert(np);
      q.emplace(np, cost + 1);
    }
  }

  return -1;
}

int main() {
  for (int N; cin >> N && N;) {
    subs.clear();
    rep(i, N) {
      string a, b;
      cin >> a >> b;
      subs.emplace_back(a, b);
    }
    cin >> initial >> target;
    cout << dodo() << endl;
  }

  return 0;
}