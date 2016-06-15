#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

string col = "rgb";

int main() {
  string worm;
  while (cin >> worm) {
    if (worm == "0") break;
    int const wsize = worm.size();
    set<string> used;
    queue<pair<int, string> > q;
    q.push(make_pair(0, worm));
    bool flg = false;
    while (!q.empty()) {
      int cost = q.front().first;
      worm = q.front().second;
      q.pop();
      if (used.count(worm)) continue;
      used.insert(worm);
      bool check = true;
      for (int i = 0; i < wsize - 1; i++)
        check = check && worm[i] == worm[i + 1];
      if (check) {
        flg = true;
        cout << cost << endl;
        break;
      }
      for (int i = 0; i < wsize - 1; i++) {
        if (worm[i] != worm[i + 1]) {
          char next;
          for (int j = 0; j < 3; j++) {
            if (worm[i] == col[j]) continue;
            if (worm[i + 1] == col[j]) continue;
            next = col[j];
          }
          string nworm = worm;
          nworm[i] = nworm[i + 1] = next;
          if (used.count(nworm)) continue;
          q.push(make_pair(cost + 1, nworm));
        }
      }
    }
    if (!flg) cout << "NA" << endl;
  }

  return 0;
}