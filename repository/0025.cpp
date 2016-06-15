#include <iostream>
using namespace std;

#define REP(i, a, n) for (int i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int a[4], b[4];
  int hit, blow;

  while (cin >> a[0]) {
    REP(i, 1, 4) cin >> a[i];
    rep(i, 4) cin >> b[i];

    hit = blow = 0;

    rep(i, 4) rep(j, 4) {
      if (a[i] == b[j]) {
        if (i == j)
          hit++;
        else
          blow++;
      }
    }

    cout << hit << " " << blow << endl;
  }

  return 0;
}