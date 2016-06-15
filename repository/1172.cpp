#include <algorithm>
#include <iostream>

#define MAX_L 123457
#define MAX_SQRT_B 123457

using namespace std;

typedef long long ll;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

void ss(ll a, ll b) {
  for (int i = 0; (ll)i * i <= b; i++) is_prime_small[i] = true;
  for (int i = 0; i <= b - a; i++) is_prime[i] = true;

  for (int i = 2; (ll)i * i <= b; i++) {
    if (is_prime_small[i]) {
      for (int j = 2 * i; (ll)j * j <= b; j += i) is_prime_small[j] = false;
      for (ll j = max(2LL, (a + i - 1) / i) * i; j <= b; j += i)
        is_prime[j - a] = false;
    }
  }
}

int main(void) {
  ll n;

  while (1) {
    cin >> n;
    if (n == 0) break;

    fill(is_prime, is_prime + MAX_L, false);
    fill(is_prime_small, is_prime_small + MAX_SQRT_B, false);

    ss(n + 1, 2 * n + 1);

    int cnt = 0;
    for (int i = n + 1; i < 2 * n; i++) {
      if (is_prime[i - (n + 1)]) cnt++;
    }
    if (n == 1) {
      cout << "1" << endl;
    } else {
      cout << cnt << endl;
    }
  }
  return 0;
}