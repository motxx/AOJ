#include <iostream>
using namespace std;

int main() {
  string str;

  while (getline(cin, str)) {
    int a[10][10];
    for (int i = 0; i < 10; i++) a[0][i] = str[i] - '0';

    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 10 - i; j++) {
        a[i][j] = (a[i - 1][j] + a[i - 1][j + 1]) % 10;
      }
    }
    cout << a[9][0] << endl;
  }

  return 0;
}