#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) REP(i, 0, n)

class Point {
 public:
  Point() {}
  Point(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}
  double x, y, z;
};

class Vector : public Point {
 public:
  void make(Point p1, Point p2) {
    x = p2.x - p1.x;
    y = p2.y - p1.y;
    z = p2.z - p1.z;
  }

  double l() { return sqrt(x * x + y * y + z * z); }
};

double dot(Vector v1, Vector v2) {
  return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

int main() {
  int n;
  Point ZeroPoint(0, 0, 0);

  while (cin >> n, n) {
    vector<Vector> s(n);
    rep(i, n) {
      Point p;
      cin >> p.x >> p.y >> p.z;
      s[i].make(ZeroPoint, p);
    }

    int m;
    cin >> m;
    vector<Vector> t(m);
    vector<double> phi(m);
    rep(i, m) {
      Point p;
      cin >> p.x >> p.y >> p.z >> phi[i];
      t[i].make(ZeroPoint, p);
    }

    vector<bool> seen(n, false);
    rep(i, n) rep(j, m) {
      double d = dot(s[i], t[j]);
      double th = acos(d / (s[i].l() * t[j].l()));
      if (th < phi[j]) seen[i] = true;
    }

    int ret = 0;
    rep(i, n) if (seen[i]) ret++;
    cout << ret << endl;
  }
  return 0;
}