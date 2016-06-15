#include <cmath>
#include <cstdio>
using namespace std;

#define sq(a) (a * a)

int main() {
  double x, h;

  while (scanf("%lf\n%lf", &x, &h) == 2 && x + h) {
    printf("%.6lf\n", sq(x) + x * (sqrt(sq(x / 2) + sq(h))) * 2);
  }

  return 0;
}