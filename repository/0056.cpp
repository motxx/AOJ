#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 50000

bool is_prime[MAX + 1];

void Sieve() {
  fill(is_prime, is_prime + MAX, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 0; i <= MAX; i++) {
    if (is_prime[i]) {
      for (int j = 2 * i; j <= MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  int n;

  Sieve();

  while (cin >> n, n) {
    int cnt = 0;
    for (int i = 2; i <= n / 2; i++) {
      if (is_prime[i] && is_prime[n - i]) {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}