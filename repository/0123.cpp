#include <iostream>

using namespace std;

int main() {
  double a, b;
  double A[] = {35.50, 37.50, 40.00, 43.00, 50.00, 55.00, 70.00};
  double B[] = {71, 77, 83, 89, 105, 116, 148};
  string C[] = {"AAA", "AA", "A", "B", "C", "D", "E", "NA"};
  while (cin >> a >> b) {
    int i;
    for (i = 0; i < 7; i++) {
      if (a < A[i] && b < B[i]) {
        break;
      }
    }
    cout << C[i] << endl;
  }
  return 0;
}