#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int W, Q;
  while (cin >> W >> Q && (W | Q)) {
    int line[W];
    memset(line, -1, sizeof line);
    rep(_, Q) {
      char ch;
      cin >> ch;
      if (ch == 's') {
        int id, w;
        cin >> id >> w;
        bool good = 0;
        rep(i, W - w + 1) {
          if (line[i] == -1) {
            bool ok = 1;
            rep(j, w) if (line[i + j] != -1) {
              ok = 0;
              break;
            }
            if (ok) {
              rep(j, w) line[i + j] = id;
              cout << i << endl;
              good = 1;
              break;
            }
          }
        }
        if (!good) {
          cout << "impossible\n";
        }
      } else {
        int id;
        cin >> id;
        rep(i, W) {
          for (int j = 0; i + j < W && line[i + j] == id; j++) line[i + j] = -1;
        }
      }
    }
    cout << "END\n";
  }

  return 0;
}