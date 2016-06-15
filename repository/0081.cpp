#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

#define Sq(x) x *x
#define EPS 1e-10

class Point {
 public:
  double x, y;

  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double k) { return Point(k * x, k * y); }
  Point operator/(double k) { return Point(x / k, y / k); }

  bool operator<(const Point &p) const { return x != p.x ? x < p.y : y < p.y; }

  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }

  double norm() { return Sq(x) + Sq(y); }
  double abs() { return sqrt(norm()); }

  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

double norm(Vector a) { return Sq(a.x) + Sq(a.y); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
Point proj(Vector base, Vector v) {
  double k = dot(base, v) / norm(base);
  return base * k;
}

int main() {
  double x, y;
  char d;
  while (cin >> x >> d >> y >> d) {
    Vector P1 = Vector(x, y);
    cin >> x >> d >> y >> d;
    Vector P2 = Vector(x, y);
    cin >> x >> d >> y;
    Vector OQ = Vector(x, y);

    Vector P1Q = OQ - P1;
    Vector P12 = P2 - P1;
    /*
       OC = P1 + proj(P12, P1Q)
       OC = ( OQ + OR ) / 2
       OR = 2*OC - OQ
     */
    Vector OR = (P1 + proj(P12, P1Q)) * 2.0 - OQ;

    printf("%.6f %.6f\n", OR.x, OR.y);
  }

  return 0;
}