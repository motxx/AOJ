#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int A = 2 * 3600;

void solve(int s) {
  int a = s / 3600;
  int b = s / 60 % 60;
  int c = s % 60;

  printf("%02d:%02d:%02d\n", a, b, c);
}

int main() {
  int h, m, s;
  while (cin >> h >> m >> s && h >= 0) {
    int a = h * 3600 + m * 60 + s;
    int aa = A - a;

    solve(aa);
    solve(aa * 3);
  }

  return 0;
}