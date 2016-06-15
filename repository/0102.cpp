#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
  int n;
  int data[11][11];

  while (1) {
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> data[i][j];

    int temp = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp += data[i][j];
      }
      data[i][n] = temp;
      temp = 0;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp += data[j][i];
      }
      data[n][i] = temp;
      temp = 0;
    }

    for (int i = 0; i < n; i++) temp += data[i][n];
    data[n][n] = temp;

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        printf("%5d", data[i][j]);
      }
      cout << endl;
    }
  }

  return 0;
}