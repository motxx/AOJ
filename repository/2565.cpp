#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

ll const inf = 1LL << 50;

ll L, R;

void find_x(pair<ll, ll> a, pair<ll, ll> b) {
  ll r = min(a.second, b.second), l = b.first;
  L = max(L, l);
  R = min(R, r);
}

int main() {
  int N;
  while (cin >> N && N) {
    vector<ll> v(N);
    rep(i, N) {
      string s;
      cin >> s;
      if (s == "x")
        v[i] = inf;
      else
        v[i] = atol(s.c_str());
    }

    vector<pair<ll, ll> > w;
    w.push_back(make_pair(-inf, inf));
    rep(i, N) {
      if (v[i] != inf) {
        continue;
      }
      if (i & 1) {  // even
        if (i - 1 >= 0) w.push_back(make_pair(v[i - 1], inf));
        if (i + 1 < N) w.push_back(make_pair(v[i + 1], inf));
      } else {
        if (i - 1 >= 0) w.push_back(make_pair(-inf, v[i - 1]));
        if (i + 1 < N) w.push_back(make_pair(-inf, v[i + 1]));
      }
    }

    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    /*
    rep(i, w.size()) {
      cout << w[i].first << ", " << w[i].second << endl;
    }
    */
    L = -inf, R = inf;
    rep(i, w.size()) REP(j, i + 1, w.size()) { find_x(w[i], w[j]); }

    if (w.size() == 1) {
      L = w[0].first, R = w[0].second;
    }

    // cerr << "L: " << L << ", R: " << R << endl;

    ll cnt = R - L;

    rep(i, N - 1) {
      if (v[i] == inf || v[i + 1] == inf) continue;
      if (i & 1 && (v[i] <= v[i + 1])) cnt = -inf;
      if (!(i & 1) && (v[i] >= v[i + 1])) cnt = -inf;
    }

    if (cnt <= 1) {
      cout << "none\n";
    } else if (cnt == 2) {
      cout << L + 1 << endl;
    } else {
      cout << "ambiguous\n";
    }
  }

  return 0;
}