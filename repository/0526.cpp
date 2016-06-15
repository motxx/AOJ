#include <iostream>
using namespace std;
int main() {
  int d[101];
  bool v[101];
  int map[101][101];
  int mx = 99999999, mn, z, a, b, c, dd, e, hozon, k, n;
  while (1) {
    for (int i = 0; i < 101; i++) {
      for (int j = 0; j < 101; j++) {
        map[i][j] = mx;
      }
      d[i] = mx;
    }
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    for (int i = 0; i < k; i++) {
      cin >> z;
      if (z == 1) {
        cin >> c >> dd >> e;
        if (map[c][dd] > e) {
          map[c][dd] = e;
          map[dd][c] = e;
        }
      } else {
        cin >> a >> b;
        for (int j = 0; j < 101; j++) {
          d[j] = mx;
          v[j] = false;
        }
        d[a] = 0;
        while (1) {
          mn = mx;
          for (int j = 0; j <= n; j++) {
            if (mn > d[j] && v[j] == false) {
              mn = d[j];
              hozon = j;
            }
          }
          // cout<<hozon<<endl;
          if (mn == mx) break;
          v[hozon] = true;
          for (int j = 0; j <= n; j++) {
            if (d[j] > map[hozon][j] + d[hozon])
              d[j] = map[hozon][j] + d[hozon];
          }
        }
        if (d[b] == mx) {
          cout << -1 << endl;
        } else {
          cout << d[b] << endl;
        }
      }
    }
  }
  return 0;
}