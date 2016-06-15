#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  int A[31];
  int n, w, a, b;
  char ch;

  cin >> w >> n;
  for (int i = 1; i <= w; i++) A[i] = i;

  for (int i = 0; i < n; i++) {
    cin >> a >> ch >> b;
    swap(A[a], A[b]);
  }

  for (int i = 1; i <= w; i++) cout << A[i] << endl;

  return 0;
}