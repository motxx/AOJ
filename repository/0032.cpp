#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  char ch;
  int rect = 0, lozen = 0;

  while (cin >> a >> ch >> b >> ch >> c) {
    if (a * a + b * b == c * c)
      rect++;
    else if (a == b)
      lozen++;
  }
  cout << rect << endl << lozen << endl;
  return 0;
}