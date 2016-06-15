#include <iostream>
using namespace std;
int euler_phi(int n) {
  int r = n;
  for (int i = 2; i * i <= n; i++) {
    if (!(n % i)) {
      r -= r / i;
      while (!(n % i)) n /= i;
    }
  }
  if (n > 1) r -= r / n;
  return r;
}
int main() {
  int n;
  cin >> n;
  cout << euler_phi(n) << endl;
  return 0;
}