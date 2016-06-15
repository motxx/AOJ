#include <algorithm>
#include <iostream>

using namespace std;

struct country {
  string name;
  int score;
  bool operator<(const country &c) const { return score > c.score; }
};

int main() {
  int n;
  bool ok = 0;
  while (cin >> n && n) {
    if (ok) cout << endl;
    ok = 1;
    country team[10];
    for (int i = 0; i < n; i++) {
      string s;
      int win, lose, draw;
      cin >> s >> win >> lose >> draw;
      team[i].name = s;
      team[i].score = win * 3 + draw * 1;
    }

    sort(team, team + n);

    for (int i = 0; i < n; i++) {
      cout << team[i].name << ',' << team[i].score << endl;
    }
  }

  return 0;
}