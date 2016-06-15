#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define X first
#define Y second

typedef pair<double, double> Pdd;

int main() {
  int n;
  double x, y;
  int cnt = 0;
  double ans;
  vector<Pdd> v;

  while (cin >> n, n) {
    v.clear();
    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      v.push_back(make_pair(x, y));
    }

    ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (v[(i + 1) % n].X - v[i].X) * (v[(i + 1) % n].Y + v[i].Y) / 2;
    }

    printf("%d %.1f\n", ++cnt, ans);
  }

  return 0;
}