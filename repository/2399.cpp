#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  while (cin >> n, n) {
    vector<vector<int> > G(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      int m;
      cin >> m;
      for (int j = 0; j < m; j++) {
        cin >> G[i][j];
      }
    }

    int k, data[100];
    cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> data[i];
    }

    int ans;
    int good = 0;
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < k; j++) {
        if (find(G[i].begin(), G[i].end(), data[j]) == G[i].end()) ok = false;
      }
      if (ok) {
        good++;
        ans = i + 1;
      }
    }
    if (good == 1)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}