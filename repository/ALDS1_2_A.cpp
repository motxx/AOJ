#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = N - 1; j > i; j--) {
      if (arr[j - 1] > arr[j]) {
        swap(arr[j - 1], arr[j]);
        cnt++;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << arr[i];
  }
  cout << endl;

  cout << cnt << endl;

  return 0;
}