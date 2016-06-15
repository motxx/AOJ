#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

/// double dp[44][44];
vector<double> ps;
int N, M;

double const pi = acos(-1);

double triangle(int s, int t, int k) {
  vector<int> idxs = {s, t, k};
  sort(idxs.begin(), idxs.end());

  double a = 2 * pi * ps[idxs[0]];
  double b = 2 * pi * ps[idxs[1]];
  double c = 2 * pi * ps[idxs[2]];

  double ba = b - a;
  double cb = c - b;
  double ac = a - c;

  while (ba < 0) {
    ba += 2 * pi;
  }
  while (cb < 0) {
    cb += 2 * pi;
  }
  while (ac < 0) {
    ac += 2 * pi;
  }

  return (sin(ba) + sin(cb) + sin(ac)) / 2.0;
}

int st;
map<pair<int, int>, double> mp;

double dfs(int curr, int rem) {
  if (rem == 0) {
    return 0.0;
  }
  if (N + st - curr + 1 <= 1) {
    return -100000000;
  }
  if (mp.find({curr, rem}) != mp.end()) {
    return mp[{curr, rem}];
  }
  auto& ret = mp[{curr, rem}];

  REP(i, curr + 1, N + st) {
    double d = triangle(st % N, curr % N, i % N);
    d += dfs(i, rem - 1);
    ret = max(ret, d);
  }
  return ret;
}

int main() {
  for (; cin >> N >> M && (N | M);) {
    ps.clear();
    ps.resize(N);
    rep(i, N) cin >> ps[i];
    sort(ps.begin(), ps.end());
    double ans = -10000000000;
    rep(i, N) {
      mp.clear();
      st = i;
      ans = max(ans, dfs(i, M - 1));
    }

    printf("%.6f\n", ans);
  }

  return 0;
}