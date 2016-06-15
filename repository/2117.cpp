#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN (14)
#define INF (1 << 29)
#define X real()
#define Y imag()

typedef complex<double> P;

template <class T>
inline T Sq(T x) {
  return x * x;
}

inline double getDist(P, P);
struct Segment {
  P s, t;
  double d;
  Segment() {}
  Segment(P s, P t) : s(s), t(t) { d = getDist(s, t); }
};

inline double getDist(P a, P b) { return sqrt(Sq(a.X - b.X) + Sq(a.Y - b.Y)); }
inline double getDist(Segment sg) {
  return sqrt(Sq(sg.s.X - sg.t.X) + Sq(sg.s.Y - sg.t.Y));
}

int n;
double dist[MAXN][2][MAXN][2];  // seg s: 0, t: 1
double dp[1 << MAXN][MAXN][2];
Segment seg[MAXN];

int main() {
  int tcase = 1;
  double x1, y1, x2, y2;
  double allseglen;

  while (cin >> n, n) {
    allseglen = 0.0;

    for (int i = 0; i < n; i++) {
      cin >> x1 >> y1 >> x2 >> y2;
      seg[i] = Segment(P(x1, y1), P(x2, y2));
      allseglen += seg[i].d;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) {
          for (int ii = 0; ii < 2; ii++) {
            for (int jj = 0; jj < 2; jj++) {
              if (ii == jj) {
                dist[i][ii][j][jj] = 0;
              } else {
                dist[i][ii][j][jj] = seg[i].d;
              }
            }
          }

          continue;
        }

        dist[i][0][j][0] = getDist(seg[i].s, seg[j].s);
        dist[i][0][j][1] = getDist(seg[i].s, seg[j].t);
        dist[i][1][j][0] = getDist(seg[i].t, seg[j].s);
        dist[i][1][j][1] = getDist(seg[i].t, seg[j].t);
      }
    }

    for (int i = 0; i < (1 << n); i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < 2; k++) dp[i][j][k] = INF;

    for (int i = 0; i < n; i++)
      for (int j = 0; j < 2; j++) dp[(1 << n) - 1][i][j] = 0;

    for (int S = (1 << n) - 1; S >= 0; S--)
      for (int v = 0; v < n; v++)
        for (int u = 0; u < n; u++)
          for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
              if (!(S >> u & 1))
                dp[S][v][j] = min(dp[S][v][j], dp[S | 1 << u][u][i] +
                                                   dist[u][(i + 1) % 2][v][j]);

    double ans = INF;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 2; j++) ans = min(ans, dp[0][i][j]);

    printf("Case %d: %f\n", tcase++, ans + allseglen);
  }

  return 0;
}