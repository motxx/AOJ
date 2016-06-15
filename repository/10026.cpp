#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int n, s[1000];
  double ave, V;

  while (cin >> n, n) {
    ave = 0;
    V = 0;

    for (int i = 0; i < n; i++) {
      cin >> s[i];
      ave += s[i];
    }
    ave /= n;
    for (int i = 0; i < n; i++) {
      V += (s[i] - ave) * (s[i] - ave);
    }
    V /= n;

    printf("%10.8f\n", sqrt(V));
  }

  return 0;
}