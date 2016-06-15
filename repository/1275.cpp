#include <iostream>
using namespace std;

int J(int n, int k) {
  if (n == 1) return 1;
  return (J(n - 1, k) + k - 1) % n + 1;
}

int main() {
  int n, k, m;

  while (cin >> n >> k >> m && n) {
    cout << (J(n - 1, k) + m - 1) % n + 1 << endl;
  }

  return 0;
}