#include <iostream>
using namespace std;

typedef long long lli;

lli gcd(lli a, lli b) { return b == 0 ? a : gcd(b, a % b); }

lli lcm(lli a, lli b) { return a * b / gcd(a, b); }

int main() {
  lli a, b;

  while (cin >> a >> b) {
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
  }
  return 0;
}