#include <bits/stdc++.h>

using namespace std;

#define MAX (10001)

bool is_prime[MAX + 1];

void Sieve() {
  fill(is_prime, is_prime + MAX, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= MAX; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  Sieve();

  int N;
  while (cin >> N) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans += is_prime[i + 1] && is_prime[N - i];
    }
    cout << ans << endl;
  }

  return 0;
}