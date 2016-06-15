#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define Sq(x) ((x) * (x))

#define Foreach(i, c) \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

const double PI = M_PI;
const double EPS = 0.0001;

struct Point {
  double x, y;

  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};

Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}

Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}

Point operator*(const Point &a, const double k) {
  return Point(a.x * k, a.y * k);
}

Point operator*(const Point &a, const Point &b) {
  return Point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

Point operator/(const Point &p, const double k) {
  return Point(p.x / k, p.y / k);
}

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

double norm(const Point &p) { return dot(p, p); }

double abs(const Point &p) { return sqrt(norm(p)); }

typedef Point Vector;

struct Circle : Point {
  double r;
  Circle(Point p = Point(0, 0), double r = 0) : Point(p), r(r) {}
};

double distPP(const Point &a, const Point &b) {
  return sqrt(Sq(a.x - b.x) + Sq(a.y - b.y));
}

bool isPointInCircle(const Point &p, const Circle &c) {
  return abs(p - c) <= c.r + EPS;
}

vector<Point> crossPointCC(const Circle &c1, const Circle &c2) {
  vector<Point> res;

  if (abs(c1 - c2) < EPS) return vector<Point>();

  double d = abs(c1 - c2);
  double rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
  double rs = sqrt(c1.r * c1.r - rc * rc);
  Point diff = (c2 - c1) / d;
  res.push_back(Point(c1 + diff * Point(rc, rs)));
  res.push_back(Point(c1 + diff * Point(rc, -rs)));
  return res;
}

Point rotate90(const Point &p) { return Point(-p.y, p.x); }

/*
ﾃ｣ﾂ??｣ﾂ?ｾﾃ｣ﾂ?湘･ﾂ仰陛｣ﾂ?凝｣ﾂ?ｪﾃ｣ﾂ??
Point rotateVector(const Vector &p, double th) {
  return Point(p.x * cos(th) - p.y*sin(th), p.x * sin(th) + p.y * cos(th));
}
*/

int main() {
  int n;
  Point p[300];

  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y;
    }

    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        if (distPP(p[i], p[j]) + EPS > 2.0) continue;

        Point cent((p[i] + p[j]) / 2);
        double a = distPP(p[i], cent);
        double b = sqrt(1.0 - a * a);

        Vector v1 = p[i] - cent;
        Vector v2 = rotate90(v1);
        Point center = cent + ((v2 / abs(v2)) * b);
        Circle c1(center, 1.0);
        int cnt = 0;
        for (int k = 0; k < n; k++) {
          cnt += isPointInCircle(p[k], c1);
        }
        ans = max(ans, cnt);

        center = cent + ((v2 / abs(v2)) * -b);
        Circle c2(center, 1.0);
        cnt = 0;
        for (int k = 0; k < n; k++) {
          cnt += isPointInCircle(p[k], c2);
        }
        ans = max(ans, cnt);
      }
    }
    cout << ans << endl;
  }

  return 0;
}