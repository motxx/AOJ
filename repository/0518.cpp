#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
//#include <map>
using namespace std;

struct Point {
  int x, y;
  Point() {}
  Point(int x, int y) : x(x), y(y) {}

  Point operator+(const Point &a) { return Point(x - a.x, y - a.y); }
  Point operator-(const Point &a) { return Point(x - a.x, y - a.y); }

  Point operator-() { return Point(-x, -y); }
  /*
  bool operator == (const Point &a) {
        return x==a.x && y==a.y;
  }
  */

  double norm() { return x * x + y * y; }
};

typedef Point Vector;

Vector rotate90R(Vector V) { return Vector(V.y, -V.x); }

bool isIn(int x, int y) { return 0 <= x && x <= 5000 && 0 <= y && y <= 5000; }

bool exist[5002][5002];

int main() {
  int n;
  int x, y;
  while (cin >> n && n) {
    vector<Point> vec;
    fill(exist[0], exist[5001], false);

    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      vec.push_back(Point(x, y));
      exist[y][x] = true;
    }
    int ans = 0;

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        Vector V1 = vec[i] - vec[j];
        Vector V3 = rotate90R(V1);
        Vector V4 = -rotate90R(V1);
        int area = V1.norm();

        int vy1 = (vec[j] + V3).y, vx1 = (vec[j] + V3).x;
        int vy2 = (vec[i] + V3).y, vx2 = (vec[i] + V3).x;
        if (isIn(vx1, vy1) && isIn(vx2, vy2))
          if (exist[vy1][vx1] && exist[vy2][vx2]) ans = max(ans, area);

        vy1 = (vec[j] + V4).y, vx1 = (vec[j] + V4).x;
        vy2 = (vec[i] + V4).y, vx2 = (vec[i] + V4).x;
        if (isIn(vx1, vy1) && isIn(vx2, vy2))
          if (exist[vy1][vx1] && exist[vy2][vx2]) ans = max(ans, area);
      }
    }
    cout << ans << endl;
  }

  return 0;
}