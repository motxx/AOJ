#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int a, b;
  int sum = 0;
  double num = 0;
  int cnt = 0;

  while (scanf("%d, %d", &a, &b) != EOF) {
    sum += a * b;
    num += b;
    cnt++;
  }

  cout << sum << endl;
  printf("%.0f\n", (num / cnt) + 0.5);
  return 0;
}