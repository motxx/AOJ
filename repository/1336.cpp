#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

#define MP make_pair

int main() {
  int N, L;
  while (cin >> N >> L && (N | L)) {
    vector<pair<int, int> > v;
    rep(i, N) {
      char d;
      int p;
      cin >> d >> p;
      v.push_back(MP(d == 'R' ? +1 : -1, p));
    }

    int time = 0;
    int ans = -1;
    int remain = N;
    while (remain > 0) {
      int ch[2200] = {};
      int *check = ch + 1100;
      rep(i, N) {
        v[i].second += v[i].first;
        check[v[i].second]++;
      }

      rep(i, N) {
        if (check[v[i].second] == 2) {
          v[i].first *= -1;
        }
      }

      bool f = 0;
      rep(i, N) {
        if (v[i].second == 0) {
          remain--;
          f = 1;
          ans = i + 1;
        }
        if (v[i].second == L) {
          remain--;
          if (!f) {
            ans = i + 1;
          }
        }
      }
      time++;
    }
    cout << time << " " << ans << endl;
  }
}