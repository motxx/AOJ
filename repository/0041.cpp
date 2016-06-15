#include <algorithm>
#include <iostream>
using namespace std;

char ope[3] = {'+', '-', '*'};

int calc(int x, int s, int y) {
  if (ope[s] == '+') return x + y;
  if (ope[s] == '-') return x - y;
  if (ope[s] == '*') return x * y;
}

int main() {
  int arr[4];
  while (cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] && arr[0]) {
    sort(arr, arr + 4);
    do {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          for (int k = 0; k < 3; k++) {
            int temp =
                calc(calc(calc(arr[0], i, arr[1]), j, arr[2]), k, arr[3]);
            if (temp == 10) {
              cout << "((" << arr[0] << ope[i] << arr[1] << ")" << ope[j]
                   << arr[2] << ")" << ope[k] << arr[3] << endl;
              goto EXIT;
            }

            temp = calc(calc(arr[0], i, arr[1]), j, calc(arr[2], k, arr[3]));
            if (temp == 10) {
              cout << "(" << arr[0] << ope[i] << arr[1] << ")" << ope[j] << "("
                   << arr[2] << ope[k] << arr[3] << ")" << endl;
              goto EXIT;
            }
          }
        }
      }
    } while (next_permutation(arr, arr + 4));

    cout << 0 << endl;

  EXIT:;
  }

  return 0;
}