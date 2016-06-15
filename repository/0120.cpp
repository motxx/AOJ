#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

#define Sq(c) ((c) * (c))

const int MAX_N = 13;
const int INF = 1 << 27;

int n;
double r[MAX_N];
double dp[(1 << MAX_N)][MAX_N];
double dist[MAX_N][MAX_N];

double rec(int S, int v) {
  if (dp[S][v] >= 0) return dp[S][v];

  if (S == (1 << n) - 1 && v == 0) return dp[S][v] = 0;

  double res = INF;
  for (int u = 0; u < n; u++) {
    if (!(S >> u & 1)) res = min(res, rec(S | 1 << u, u) + dist[v][u]);
  }
  return dp[S][v] = res;
}

int main() {
  double width;
  string str;

  while (getline(cin, str)) {
    stringstream ss(str);

    ss >> width;
    n = 0;
    while (ss >> r[n]) n++;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = sqrt(Sq(r[i] + r[j]) - Sq(r[i] - r[j]));
      }
    }
    // ﾃ･ﾂｷﾂｦﾃ･ﾂ渉ｳﾃ､ﾂｸﾂ｡ﾃｧﾂｫﾂｯﾃ｣ﾂ?ｫﾃｦﾂｳﾂｨﾃｦﾂ??
    for (int i = 0; i < n; i++) {
      dist[i][n] = dist[n][i] = r[i];
    }
    n++;

    if (rec(0, 0) <= width)
      cout << "OK" << endl;
    else
      cout << "NA" << endl;

    // printf("%lf\n", dp[0][0]);
  }

  return 0;
}