#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int *arr = new int[N];

  for (int i = 0; i < N; i++) cin >> arr[i];

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    int min = i;
    for (int j = i; j < N; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (i != min) {
      cnt++;
      swap(arr[i], arr[min]);
    }
  }

  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << arr[i];
  }
  cout << endl << cnt << endl;

  return 0;
}