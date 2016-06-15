#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

vector<string> V;
string v[20];

ll dp[1 << 20][18];
ll cost[18][18];
ll const INF = 1 << 29;

string rcon;

inline bool cmp(string const& a, string const& b) {
  if (a.size() != b.size()) return a.size() < b.size();
  return a < b;
}

bool contains(string const& a, string const& b) {
  int asize = a.size(), bsize = b.size();

  rep(i, asize) {
    bool ok = 1;
    rep(j, bsize) {
      if (i + j >= asize) {
        ok = 0;
        break;
      }
      if (a[i + j] != b[j]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      return true;
    }
  }

  return false;
}

string concat(string const& a, string const& b) {
  string ret = a + b;

  int n = a.size(), m = b.size();
  for (int i = n - 1; i >= 0; i--) {  // start
    bool ok = 1;
    rep(j, m) {  // len
      if (i + j >= n) {
        break;
      }
      if (a[i + j] != b[j]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      if (n - i < m) {
        ret = min(ret, a + b.substr(n - i), cmp);
      }
    }
  }
  return ret;
}

int main() {
  int n, N;

  while (cin >> n && n) {
    V.resize(n);
    rep(i, n) { cin >> V[i]; }

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    n = V.size();

    set<int> unuse;
    rep(i, n) {
      rep(j, n) {
        if (i == j) {
          continue;
        }
        if (contains(V[i], V[j])) {
          unuse.insert(j);
        }
      }
    }

    N = 0;
    rep(i, n) {
      if (!unuse.count(i)) {
        v[N++] = V[i];
      }
    }

    rep(i, N) {
      cost[i][i] = 0;
      rep(j, N) {
        if (i == j) {
          continue;
        }
        string re = concat(v[i], v[j]);
        cost[i][j] = (int)re.size() - v[i].size();
      }
    }

    rep(i, 1 << N) rep(j, N) dp[i][j] = INF;
    rep(i, N) { dp[1 << i][i] = v[i].size(); }

    rep(S, 1 << N) {
      rep(i, N) {
        if (dp[S][i] == INF) {
          continue;
        }
        rep(j, N) {
          if (S >> j & 1) {
            continue;
          }
          int next = S | (1 << j);
          if (dp[next][j] > dp[S][i] + cost[i][j]) {
            dp[next][j] = dp[S][i] + cost[i][j];
          }
        }
      }
    }

    ll ans = 1 << 29;
    rep(i, N) { ans = min(ans, dp[(1 << N) - 1][i]); }

    cout << ans << endl;
  }

  return 0;
}