#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int W, D;
  while (cin >> W >> D && (W | D)) {
    vector<int> h1(W), h2(D);
    map<int, int> mp1, mp2;
    int mx = 0;
    rep(i, W) {
      cin >> h1[i];
      mp1[h1[i]]++;
      mx = max(mx, h1[i]);
    }
    rep(i, D) {
      cin >> h2[i];
      mp2[h2[i]]++;
      mx = max(mx, h2[i]);
    }

    int ans = 0;
    /*
    for(map<int, int>::iterator it=mp1.begin(); it!=mp1.end(); it++) {
      ans += max(it->second, mp2[it->first])*it->first;
    }
    */
    for (int i = 1; i <= mx; i++) {
      ans += max(mp1[i], mp2[i]) * i;
    }

    cout << ans << endl;
  }

  return 0;
}