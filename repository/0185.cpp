#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000
typedef long long ll;

void ESieve(ll n, vector<bool> &ispr) {
  ispr.assign(n + 1, true);
  ispr[0] = ispr[1] = false;

  for (int i = 0; (ll)i * i <= n; i++) {
    if (ispr[i]) {
      for (int j = 2 * i; j <= n; j += i) {
        ispr[j] = false;
      }
    }
  }
}

int main() {
  vector<bool> isPrime;
  ESieve(MAX, isPrime);

  int n;
  while (cin >> n, n) {
    int res = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (isPrime[i] && isPrime[n - i]) {
        res++;
      }
    }
    cout << res << endl;
  }
  return 0;
}