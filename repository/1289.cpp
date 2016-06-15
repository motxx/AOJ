#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

using namespace std;

#define INF (1e10)
#define EPS (1e-7)
double const PI = acos(-1);

struct Point3D {
  double x, y, z;
  Point3D() {}
  Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

  Point3D operator+(const Point3D &p) const {
    return Point3D(x + p.x, y + p.y, z + p.z);
  }

  Point3D operator-(const Point3D &p) const {
    return Point3D(x - p.x, y - p.y, z - p.z);
  }

  Point3D operator*(double k) const { return Point3D(x * k, y * k, z * k); }

  Point3D operator/(double k) const { return Point3D(x / k, y / k, z / k); }
};

double dot(const Point3D &a, const Point3D &b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

double norm(const Point3D &p) { return dot(p, p); }

double abs(const Point3D &p) { return sqrt(norm(p)); }

double cross(const Point3D &a, const Point3D &b) {
  return abs(Point3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                     a.x * b.y - a.y * b.x));
}

istream &operator>>(istream &is, Point3D &p) { return is >> p.x >> p.y >> p.z; }

ostream &operator<<(ostream &os, Point3D &p) {
  return os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

struct LineSD {
  Point3D src, dir;
  LineSD() {}
  LineSD(Point3D src, Point3D dir) : src(src), dir(dir) {}
};

ostream &operator<<(ostream &os, LineSD &l) {
  return os << "[ src: " << l.src << ", dir: " << l.dir << " ]";
}

Point3D projection(const LineSD &l, const Point3D &p) {
  double t = dot(p - l.src, l.dir) / norm(l.dir);
  return l.src + l.dir * t;
}

double distanceLP(const LineSD &l, const Point3D &p) {
  return abs(p - projection(l, p));
}

struct Sphere {
  Point3D p;
  double r;
  Sphere() {}
  Sphere(Point3D p, double r) : p(p), r(r) {}
};

LineSD reflectionSL(const Sphere &s, const Point3D &crp, const LineSD &l) {
  auto &O = s.p;
  auto &P = crp;
  double theta = acos(dot(l.src - P, P - O) / abs(l.src - P) / abs(P - O));
  double phi = PI / 2 - theta;
  double K = abs(l.src - P) * sin(phi);
  Point3D e = (O - P) / abs(O - P);
  Point3D S = l.src + e * (K * 2);
  Point3D R = P + (P - S);
  return LineSD(P, R - P);
}

bool isIntersectSL(const Sphere &s, const LineSD &l) {
  return distanceLP(l, s.p) <= s.r + EPS;
}

vector<Point3D> getIntersectSL(const Sphere &s, const LineSD &l) {
  auto &O = s.p;
  auto T = projection(l, s.p);
  auto TO = T - O;
  auto e = l.dir / abs(l.dir);
  auto len = sqrt(s.r * s.r - norm(TO));
  return {T + e * len, T - e * len};
}

vector<Sphere> spheres;
Point3D src;
LineSD L;

pair<int, Point3D> get_next_sphere() {
  double minDist = INF;
  Point3D retp;
  int midx = -1;
  rep(i, spheres.size()) {
    auto &sphere = spheres[i];
    if (!isIntersectSL(sphere, L)) continue;
    auto vec = getIntersectSL(sphere, L);
    assert(!vec.empty());
    if (abs(vec[0] - (L.src - L.dir)) < abs(vec[0] - (L.src + L.dir))) continue;
    double md = INF;
    Point3D p;
    for (auto &&e : vec) {
      double d = abs(e - L.src);
      if (md > d) md = d, p = e;
    }
    if (md < EPS) continue;
    if (minDist > md) {
      minDist = md;
      midx = i;
      retp = p;
    }
  }
  return make_pair(midx, retp);
}

void solve() {
  L = LineSD(Point3D(0, 0, 0), src);
  while (1) {
    int sphere_idx;
    Point3D crp;
    tie(sphere_idx, crp) = get_next_sphere();
    if (sphere_idx == -1)
      break;
    else
      L = reflectionSL(spheres[sphere_idx], crp, L);
  }
  printf("%.10f %.10f %.10f\n", L.src.x, L.src.y, L.src.z);
}

int main() {
  int N;
  while (cin >> N, N) {
    spheres.clear();
    spheres.resize(N);
    cin >> src;
    for (int i = 0; i < N; i++) {
      cin >> spheres[i].p >> spheres[i].r;
    }
    solve();
  }
  return 0;
}