#include <iostream>
using namespace std;

string rec(int n) {
  if (n == 0) return "";
  int k = n % 8;
  return rec(n / 8) + "01235789"[k];
}

int main() {
  int n;
  while (1) {
    cin >> n;
    if (n == 0) break;
    cout << rec(n) << endl;
  }

  return 0;
}