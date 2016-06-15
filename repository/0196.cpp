#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;

  while (cin >> n, n) {
    vector<vector<int> > G(n, vector<int>(n - 1, 0));
    vector<int> win(n), lose(n);
    vector<pair<int, string> > team(n);

    for (int i = 0; i < n; i++) {
      team[i].first = i;
      cin >> team[i].second;
      for (int j = 0; j < n - 1; j++) {
        cin >> G[i][j];
        win[i] += G[i][j] == 0;
        lose[i] += G[i][j] == 1;
      }
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (win[i] == win[j]) {
          if (lose[i] == lose[j] && team[i].first > team[j].first) {
            swap(win[i], win[j]);
            swap(lose[i], lose[j]);
            swap(team[i], team[j]);
          } else if (lose[i] > lose[j]) {
            swap(win[i], win[j]);
            swap(lose[i], lose[j]);
            swap(team[i], team[j]);
          }
        } else if (win[i] < win[j]) {
          swap(win[i], win[j]);
          swap(lose[i], lose[j]);
          swap(team[i], team[j]);
        }
      }
    }
    for (int i = 0; i < n; i++) cout << team[i].second << endl;
  }

  return 0;
}