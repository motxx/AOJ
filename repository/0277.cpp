#include <iostream>
using namespace std;

int main() {
  int m[] = {6000, 4000, 3000, 2000};
  int a, b;

  for (int i = 0; i < 4; i++) {
    cin >> a >> b;
    cout << b * m[a - 1] << endl;
  }

  return 0;
}