#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;
double x[100], y[100], z[100], r[100];
int n, m, t;
double MX = 1 << 20, mn;
double mp[100][100];
double sumcor;
int p[100];
double d[100];
int visited[100];

// distance i, j
double compute(int i, int j) {
  double ret;

  ret = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) +
             (z[i] - z[j]) * (z[i] - z[j])) -
        (r[i] + r[j]);

  if (ret < 0) ret = 0;

  return ret;
}

int main() {
  double res = 0;

  while (1) {
    cin >> n;
    if (n == 0) break;

    for (int i = 0; i < n; i++) {
      cin >> x[i];
      cin >> y[i];
      cin >> z[i];
      cin >> r[i];
    }

    // init p, d, visited, map, res
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        mp[i][j] = MX;
      }
      p[i] = -1;
      d[i] = MX;
      visited[i] = 0;
    }
    res = 0;

    // distance between 2 cells
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          mp[i][j] = 0;
        } else {
          mp[i][j] = compute(i, j);
        }
      }
    }

    d[0] = 0;
    t = 0;
    while (1) {
      mn = MX;
      // Renew target
      for (int i = 0; i < n; i++) {
        if (d[i] < mn && visited[i] == 0) {
          mn = d[i];
          t = i;
        }
      }

      if (mn == MX) break;

      visited[t] = 1;
      res += d[t];
      // if (p[t] != -1) res += mp[t][p[t]];
      // printf("res: %.3f\n", res);

      //
      for (int v = 0; v < n; v++) {
        if (mp[t][v] < d[v] && visited[v] == 0) {
          d[v] = mp[t][v];
          p[v] = t;
        }
      }
    }
    printf("%.3f\n", res);
  }

  return 0;
}