#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N;
  while (cin >> N && N) {
    string s;
    cin >> s;
    vector<int> player(N);
    int const size = s.size();
    int onfield = 0;
    int turn = 0;
    rep(i, size) {
      if (s[i] == 'M') {
        player[turn]++;
      }
      if (s[i] == 'L') {
        player[turn] += onfield + 1;
        onfield = 0;
      }
      if (s[i] == 'S') {
        player[turn]++;
        onfield += player[turn];
        player[turn] = 0;
      }
      (++turn) %= N;
    }
    sort(player.begin(), player.end());
    rep(i, N) {
      cout << player[i];
      cout << " ";
    }
    cout << onfield << endl;
  }

  return 0;
}