#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// !!! EPS は 1e-10 !!!
#define EPS (1e-10)
static const double PI = M_PI;

class Point {
 public:
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double k) { return Point(k * x, k * y); }
  Point operator/(double k) { return Point(x / k, y / k); }

  double abs() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
};

typedef Point Vector;

double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a)); }
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

enum { COUNTER_CLOCKWISE, CLOCKWISE, ONLINE_BACK, ONLINE_FRONT, ON_SEGMENT };

int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (norm(a) < norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isConvex(vector<Point> P) {
  int N = P.size();
  if (P.size() < 3) return false;  // 三角形を作れないなら false を返す
  int c = ccw(P[0], P[1], P[2]);
  for (int i = 1; i < N; i++) {
    if (c != ccw(P[i], P[(i + 1) % N], P[(i + 2) % N])) return false;
  }
  return true;
}

int main() {
  char ch;
  vector<Point> P(4);

  while (cin >> P[0].x >> ch >> P[0].y) {
    for (int i = 1; i < 4; i++) cin >> ch >> P[i].x >> ch >> P[i].y;
    if (isConvex(P))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}