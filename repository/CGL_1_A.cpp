#include <complex>
#include <cstdio>
#include <iostream>

using namespace std;

#define X real()
#define Y imag()

const double EPS = 1e-8;

typedef complex<double> Point;

bool operator<(const Point& p1, const Point& p2) {
  return p1.X != p2.X ? p1.X < p2.X : p1.Y < p2.Y;
}

double dot(const Point& p1, const Point& p2) { return (conj(p1) * p2).X; }

typedef Point Vector;

int main() {
  Point p0, p1;
  double x, y;

  cin >> x >> y;
  p0 = Point(x, y);
  cin >> x >> y;
  p1 = Point(x, y);

  Vector v0 = p1 - p0;

  int q;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    Vector v1 = Point(x, y) - p0;
    Point ans = p0 + dot(v0, v1) * v0 / norm(v0);
    printf("%.9lf %.9lf\n", ans.X, ans.Y);
  }

  return 0;
}