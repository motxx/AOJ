#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int x = *a;
  a = b;
  b = &x;
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j > i; j--) {
      if (arr[j - 1] > arr[j]) swap(arr[j - 1], arr[j]);
    }
  }
}

int main() {
  int n;
  int arr[1000];

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  bubbleSort(arr, n);

  for (int i = 0; i < n - 1; i++) cout << arr[i] << " ";
  cout << arr[n - 1] << endl;

  return 0;
}