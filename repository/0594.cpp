#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define X first
#define Y second

typedef pair<int, int> Pii;

int main() {
  int w, h, n;
  vector<Pii> p;

  cin >> w >> h >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    p.push_back(make_pair(x, y));
  }

  int res = 0;
  int const N = p.size();
  for (int i = 0; i < N - 1; i++) {
    int ww = p[i].X - p[i + 1].X;
    int hh = p[i].Y - p[i + 1].Y;
    if (ww * hh > 0)
      res += min(abs(ww), abs(hh)) + abs(abs(ww) - abs(hh));
    else
      res += abs(ww) + abs(hh);
  }

  cout << res << endl;

  return 0;
}