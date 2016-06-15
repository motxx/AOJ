#include <iostream>

using namespace std;

int main(void) {
  int n;
  int Array[200][3];

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> Array[i][j];
    }
  }

  int j, score[200] = {0};

  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i == j) continue;
        if (Array[j][k] == Array[i][k]) break;
      }

      if (n == j) score[i] += Array[i][k];
    }
  }

  for (int i = 0; i < n; i++) {
    cout << score[i] << endl;
  }

  return 0;
}