#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;

#define X first
#define Y second
typedef pair<double, double> Point;

double sq(double a) { return a * a; }

double gD(Point p1, Point p2) {
  return sqrt(sq(p1.X - p2.X) + sq(p1.Y - p2.Y));
}

int main() {
  Point p[123456];
  char ch;
  int n = 0;
  for (int i = 0; cin >> p[i].X >> ch >> p[i].Y; i++) n++;
  double S = 0;
  for (int i = 1; i < n - 1; i++) {
    double a = gD(p[0], p[i]), b = gD(p[i], p[i + 1]), c = gD(p[i + 1], p[0]);
    double z = (a + b + c) / 2;
    S += sqrt(z * (z - a) * (z - b) * (z - c));
  }
  printf("%.8f\n", S);

  return 0;
}