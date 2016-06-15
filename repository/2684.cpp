#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
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

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

void change(deque<pair<char, int>>& nv0) {
  if (nv0.size() > 1 && nv0[nv0.size() - 2].first == nv0.back().first) {
    int k = nv0.back().second;
    nv0.pop_back();
    nv0.back().second += k;
  }
}

void output(deque<pair<char, int>>& out) {
  rep(i, out.size()) {
    if (i) cout << " ";
    cout << out[i].first << " " << out[i].second;
  }
  cout << " $" << endl;
}

int main() {
  vector<deque<pair<char, int>>> v(3);
  for (auto& u : v) {
    while (1) {
      char c;
      cin >> c;
      if (c == '$') break;
      int n;
      cin >> n;
      u.emplace_back(c, n);
    }
  }

  rep(i, (int)v[0].size() - (int)v[1].size() + 1) {
    if (v[1].size() == 1) {
      const int a = v[0][i].second, b = v[1][0].second;
      if (v[0][i].first == v[1][0].first && a >= b) {
        deque<pair<char, int>> nv0;
        rep(k, i) { nv0.push_back(v[0][k]); }

        rep(k, v[2].size()) {
          nv0.push_back(v[2][k]);
          change(nv0);
        }

        if (a - b > 0) {
          nv0.push_back(v[0][i]);
          nv0.back().second = a - b;
          change(nv0);
        }
        REP(k, i + 1, v[0].size()) {
          nv0.push_back(v[0][k]);
          change(nv0);
        }
        v[0] = nv0;
        break;
      } else {
        continue;
      }
    }

    int j = 0;
    vector<int> V;
    while (j < v[1].size() && v[0][i + j].first == v[1][j].first) {
      if (j == 0 || j == (int)v[1].size() - 1) {
        if (v[0][i + j].second < v[1][j].second) break;
        V.push_back(v[0][i + j].second - v[1][j].second);
      } else {
        if (v[0][i + j].second != v[1][j].second) break;
      }
      j++;
    }

    deque<pair<char, int>> nv0;

    if (j == v[1].size()) {
      rep(k, v[0].size()) {
        if (k < i) {
          nv0.push_back(v[0][k]);
          change(nv0);
        }
        if (k == i) {
          if (V[0] > 0) nv0.emplace_back(v[0][i].first, V[0]);
          rep(l, v[2].size()) {
            nv0.push_back(v[2][l]);
            change(nv0);
          }
          k = i + v[1].size() - 1;
        }
        if (k == i + j - 1) {
          if (V[1] > 0) nv0.emplace_back(v[0][i + j - 1].first, V[1]);
          change(nv0);
        }
        if (i + j <= k) {
          nv0.push_back(v[0][k]);
          change(nv0);
        }
      }
      v[0] = nv0;
      break;
    }
  }

  output(v[0]);

  return 0;
}