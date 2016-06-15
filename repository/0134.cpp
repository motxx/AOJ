#include <iostream>
using namespace std;
int main() {
  long long n, x, a = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a += x;
  }
  a /= n;
  cout << a << endl;
  return 0;
}