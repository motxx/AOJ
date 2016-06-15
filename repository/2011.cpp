#include <cstring>
#include <iostream>
#include <set>
using namespace std;

bool data[55][31];
int N;

int main() {
  while (cin >> N && N) {
    memset(data, false, sizeof data);
    for (int i = 0; i < N; i++) {
      int k;
      cin >> k;
      while (k--) {
        int h;
        cin >> h;
        data[i][h] = true;
      }
    }

    bool flag = false;
    set<int> st[51];
    for (int i = 0; i < N; i++) {
      st[i].insert(i);
    }

    for (int i = 1; i < 31; i++) {
      for (int j = 0; j < N; j++) {
        if (!data[j][i]) continue;
        for (int k = j + 1; k < N; k++) {
          if (!data[k][i]) continue;
          st[j].insert(st[k].begin(), st[k].end());
          st[k] = st[j];
        }

        if (st[j].size() == N) {
          cout << i << endl;
          flag = true;
          goto EXIT;
        }
      }
    }

  EXIT:;
    if (!flag) cout << -1 << endl;
  }

  return 0;
}