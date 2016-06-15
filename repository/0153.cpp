#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;

#define F first
#define S second

#define X real()
#define Y imag()

#define EPS (1e-7)

typedef complex<double> Point;
typedef vector<Point> Polygon;
typedef pair<double, Point> Circle;

bool isPointInCircle(const Point& p, const Circle& c) {
  if (abs(p - c.S) < abs(c.F) + EPS) return true;
  return false;
}

double dot(const Point& a, const Point& b) { return a.X * b.X + a.Y * b.Y; }

double cross(const Point& a, const Point& b) { return a.X * b.Y - a.Y * b.X; }

typedef pair<Point, Point> Segment;
typedef Segment Line;

double distanceLP(Line l, Point p) {
  return abs(cross(l.S - l.F, p - l.F)) / abs(l.S - l.F);
}

double distanceSP(Segment s, Point p) {
  Point a = s.F, b = s.S;

  if (dot(b - a, p - a) < EPS) return abs(p - a);
  if (dot(a - b, p - b) < EPS) return abs(p - b);
  return distanceLP(s, p);
}

enum struct ECont { OUT, ON, IN };
ECont contains(const Polygon& poly, const Point& p) {
  bool in = 0;
  for (int i = 0; i < poly.size(); i++) {
    Point a = poly[i] - p, b = poly[(i + 1) % poly.size()] - p;
    if (a.imag() > b.imag()) swap(a, b);
    if (a.imag() <= 0 && 0 < b.imag()) {
      if (cross(a, b) < 0) in = !in;
    }
    if (cross(a, b) == 0 && dot(a, b) <= 0) return ECont::ON;
  }

  return in ? ECont::IN : ECont::OUT;
}

int main() {
  while (1) {
    Polygon points(3);
    Circle circle;

    for (int i = 0; i < 3; i++) {
      double x, y;
      cin >> x >> y;
      if (x == 0) return 0;

      points[i] = Point(x, y);
    }

    {
      double x, y;
      cin >> x >> y;
      circle.S = Point(x, y);
      cin >> circle.F;
    }

    bool ok = 1;
    for (int i = 0; i < 3; i++) {
      ok &= isPointInCircle(points[i], circle);
    }
    if (ok) {
      cout << 'b' << endl;
      continue;
    }

    int uncross = 0;
    for (int i = 0; i < 3; i++) {
      Segment seg = make_pair(points[(i + 1) % 3], points[i]);
      uncross += circle.F < distanceSP(seg, circle.S) + EPS;
    }
    if (uncross == 3 && contains(points, circle.S) == ECont::IN) {
      cout << 'a' << endl;
      continue;
    }

    int cross = 0;
    for (int i = 0; i < 3; i++) {
      Segment seg = make_pair(points[(i + 1) % 3], points[i]);
      cross += distanceSP(seg, circle.S) <= circle.F + EPS;
    }
    if (cross > 0)
      cout << 'c' << endl;
    else
      cout << 'd' << endl;
  }

  return 0;
}