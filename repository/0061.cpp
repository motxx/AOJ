#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int rank[10000];

  char ch;
  int a, b;
  int cnt = 0;
  while (cin >> a >> ch >> b, a + b) {
    rank[a] = b;
    cnt++;
  }

  int q;
  while (cin >> q) {
    int c = 1;
    bool dbl[32];
    fill(dbl, dbl + 31, false);
    for (int i = 1; i <= cnt; i++) {
      if (rank[q] < rank[i] && !dbl[rank[i]]) {
        c++;
        dbl[rank[i]] = true;
      }
    }

    cout << c << endl;
  }

  return 0;
}