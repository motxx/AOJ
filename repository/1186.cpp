#include <algorithm>
#include <iostream>
using namespace std;

struct Rect {
  int h, w, diagonal;
  void norm() { diagonal = h * h + w * w; }
  bool operator<(const Rect &r) const {
    return diagonal != r.diagonal ? diagonal < r.diagonal : h < r.h;
  }
};

int main() {
  Rect r[150][150];

  for (int i = 0; i < 150; i++) {
    for (int j = 0; j < 150; j++) {
      r[i][j].h = i + 1, r[i][j].w = j + 1;
      r[i][j].norm();
    }
  }

  sort(r[0], r[0] + 150 * 150);

  Rect rin;
  while (cin >> rin.h >> rin.w, rin.h + rin.w) {
    rin.norm();
    for (int i = 0; i < 150; i++) {
      for (int j = 0; j < 150; j++) {
        if (rin < r[i][j] && r[i][j].h < r[i][j].w) {
          cout << r[i][j].h << ' ' << r[i][j].w << endl;
          goto Fin;
        }
      }
    }
  Fin:;
  }

  return 0;
}