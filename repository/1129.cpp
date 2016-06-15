#include <iostream>

using namespace std;

int main(void) {
  int before[50], after[50];
  int n, r, p, c;
  int i, j, k;

  while (1) {
    cin >> n;

    for (i = 0; i < n; i++) {
      before[i] = n - i;
      //    cout << before[i] << endl;
    }
    //    cout << endl;

    cin >> r;

    if (n == 0 && r == 0) break;

    for (i = 0; i < r; i++) {
      cin >> p;
      cin >> c;

      for (j = 0; j < c; j++) {
        after[j] = before[p - 1 + j];
      }
      for (k = 0; k < p - 1; j++, k++) {
        after[j] = before[k];
      }
      for (; j < n; j++) {
        after[j] = before[j];
      }

      for (j = 0; j < n; j++) {
        before[j] = after[j];
        //	cout << after[j] << endl;
      }

      // cout << endl;
    }

    cout << after[0] << endl;
  }

  return 0;
}