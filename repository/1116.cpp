#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>

using namespace std;

string puzzle[9];
int pl2id[9], pl2rot[9];

bool check(char a, char b) { return toupper(a) == toupper(b) && a != b; }

int dfs(int k, bool *used) {
  if (k == 9) return 1;

  /*
  for(int i=0; i<9; i++) {
    cout << " " << used[i];
  }
  cout << endl;
  */

  int ret = 0;
  for (int id = 0; id < 9; id++) {
    if (used[id]) continue;

    for (int rot = 0; rot < 4; rot++) {
      bool ok = true;
      // 上と一致
      if (k >= 3)
        ok &= check(puzzle[id][(rot + 1) % 4],
                    puzzle[pl2id[k - 3]][(pl2rot[k - 3] + 3) % 4]);
      // 左と一致
      if (k % 3 > 0)
        ok &= check(puzzle[id][rot],
                    puzzle[pl2id[k - 1]][(pl2rot[k - 1] + 2) % 4]);

      if (ok) {
        pl2id[k] = id;
        pl2rot[k] = rot;
        used[id] = true;
        ret += dfs(k + 1, used);
        used[id] = false;
      }
    }
  }

  return ret;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    for (int i = 0; i < 9; i++) {
      cin >> puzzle[i];
    }

    bool used[9] = {};
    cout << dfs(0, used) << endl;
  }

  return 0;
}