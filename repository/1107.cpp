#include <algorithm>
#include <complex>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef complex<double> P;

const double EPS = 1e-10;

double dot(P a, P b) { return real(conj(a) * b); }
double cross(P a, P b) { return imag(conj(a) * b); }

enum { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT };
int ccw(P c, P a, P b) {
  a = a - c;
  b = b - c;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (norm(a) < norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

int main() {
  int n;
  while (cin >> n && n) {
    vector<P> p(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      p[i] = P(x, y);
    }

    vector<bool> used(n);
    P curr(0, 0);
    double ans = 0.0;

    for (int i = 0; i < n; i++) {
      int num = -1;
      for (int j = 0; j < n; j++) {
        if (!used[j]) {
          if (num == -1) {
            num = j;
          } else {
            int c = ccw(curr, p[num], p[j]);
            if (c == COUNTER_CLOCKWISE || c == ON_SEGMENT) {
              // ﾃ･ﾂ?湘ｨﾂｧﾂ津｣ﾂ?ｮﾃ･ﾂｷﾂｮﾃ｣ﾂ?古｣ﾂつ暗｣ﾂつ甘･ﾂｰﾂ湘｣ﾂ?陛｣ﾂ?湘｣ﾂ??｣ﾂつ暗｣ﾂつ甘･ﾂ､ﾂｧﾃ｣ﾂ?催｣ﾂ?陛｣ﾂ?古･ﾂｰﾂ湘｣ﾂ?陛｣ﾂ??｣ﾂつづ｣ﾂ?ｮﾃ｣ﾂつ津ｩﾂ?ｸﾃｦﾂ環?
              num = j;
            }
          }
        }
      }
      ans += sqrt(norm(p[num] - curr));
      used[num] = true;
      curr = p[num];
    }
    printf("%.1f\n", round(ans * 10) / 10.0);
  }
  return 0;
}