#include <math.h>
#include <stdio.h>

//#define pi 3.141592648
#define pi M_PI

int main(void) {
  double r;

  scanf("%lf", &r);
  printf("%.8f %.8f\n", pi * r * r, 2.0 * pi * r);

  return 0;
}