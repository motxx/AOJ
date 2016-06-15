#include <algorithm>
#include <iostream>
using namespace std;

bool check(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] != i + 1) return false;
  }
  return true;
}

int main() {
  int n;
  int arr[10000];

  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int turn;
    bool good = true;
    for (turn = 0; turn < 10000; turn++) {
      if (n == 0) {
        good = false;
        break;
      }
      if (check(arr, n)) break;

      for (int i = 0; i < n; i++) {
        arr[i]--;
      }

      arr[n] = n;
      n++;

      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (arr[i]) {
          arr[cnt++] = arr[i];
        }
      }
      n = cnt;
    }
    if (turn == 10000 || !good)
      cout << -1 << endl;
    else
      cout << turn << endl;
  }

  return 0;
}