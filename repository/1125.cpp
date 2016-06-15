#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 501

int M[MAX][MAX];

int main() {
  int n;
  int w, h;
  int x, y;
  int s, t;
  int cnt, mx;

  while (cin >> n && n) {
    cin >> w >> h;
    fill(M[0], M[0] + MAX * MAX, 0);

    for (int i = 0; i < n; i++) {
      cin >> x >> y;
      M[y][x] = 1;
    }

    cin >> s >> t;
    mx = 0;

    for (int i = 1; i < h - t + 2; i++) {
      for (int j = 1; j < w - s + 2; j++) {
        cnt = 0;
        for (int k = 0; k < t; k++) {
          for (int l = 0; l < s; l++) {
            if (M[i + k][j + l]) cnt++;
          }
        }
        mx = max(mx, cnt);
      }
    }
    cout << mx << endl;
  }

  return 0;
}