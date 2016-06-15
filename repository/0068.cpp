#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) ((fabs(a) - (b)) < EPS)
#define dle(a, b) (equals(a, b) || a < b)

class Point {
 public:
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double k) { return Point(x * k, y * k); }
  Point operator/(double k) { return Point(x / k, y / k); }

  double norm() { return x * x + y * y; }
  double abs() { return sqrt(norm()); }

  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
};

typedef Point Vector;

typedef vector<Point> Polygon;

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
Point polar(double a, double r) { return Point(cos(r) * a, sin(r) * a); }
double getDistance(Vector a, Vector b) { return abs(a - b); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;

  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (norm(a) < norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool yxCmp(const Point &p1, const Point &p2) {
  return (p1.y == p2.y) ? p1.x < p2.x : p1.y < p2.y;
}

class PolarAngleCmp {
 public:
  Point o;
  PolarAngleCmp(Point o) : o(o) {}
  bool operator()(const Point &p1, const Point &p2) const {
    Vector a = Vector(p1.x - o.x, p1.y - o.y);
    Vector b = Vector(p2.x - o.x, p2.y - o.y);
    double c = cross(a, b);
    if (c == 0) return abs(a) < abs(b);
    return c > 0;
  }
};

Polygon grahamScan(Polygon &s) {
  Polygon h;
  Point lm = *min_element(s.begin(), s.end(), yxCmp);
  sort(s.begin(), s.end(), PolarAngleCmp(lm));
  for (int i = 0; i <= 2; i++) h.push_back(s[i]);
  for (int i = 3; i < s.size(); i++) {
    while (h.size() >= 2 && ccw(h[h.size() - 2], h.back(), s[i]) == CLOCKWISE)
      h.pop_back();
    h.push_back(s[i]);
  }
  return h;
}

int main() {
  char ch;
  int n;

  while (cin >> n, n) {
    Polygon pl, all;
    double x, y;
    for (int i = 0; i < n; i++) {
      cin >> x >> ch >> y;
      pl.push_back(Point(x, y));
    }
    all = grahamScan(pl);
    cout << pl.size() - all.size() << endl;
  }
  return 0;
}