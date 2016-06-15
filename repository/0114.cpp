#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

int main() {
  int a[3], m[3];

  while (true) {
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
      cin >> m[i];
    }
    if (a[0] == 0) break;

    ll x = 1, y = 1, z = 1;
    ll cnt[3] = {};
    for (;;) {
      x = a[0] * x % m[0];
      cnt[0]++;
      if (x == 1) break;
    }
    for (;;) {
      y = a[1] * y % m[1];
      cnt[1]++;
      if (y == 1) break;
    }
    for (;;) {
      z = a[2] * z % m[2];
      cnt[2]++;
      if (z == 1) break;
    }
    cout << lcm(lcm(cnt[0], cnt[1]), cnt[2]) << endl;
  }

  return 0;
}