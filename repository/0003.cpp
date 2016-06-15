#include <iostream>

using namespace std;

void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main(void) {
  int n;
  int a, b, c;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;

    if (a > b) {
      swap(a, b);
    }
    if (b > c) {
      swap(b, c);
    }

    if (a * a + b * b == c * c) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}