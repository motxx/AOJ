#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 1000001

bool is_prime[MAX];

void Sieve() {
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i < MAX; i++) is_prime[i] = 1;

  for (int i = 2; i * i < MAX; i++) {
    if (is_prime[i]) {
      for (int j = 2 * i; j < MAX; j += i) {
        is_prime[j] = 0;
      }
    }
  }
}

int main() {
  Sieve();

  int n, a, b;
  while (cin >> n >> a, n + a) {
    bool c[MAX] = {};
    c[0] = 1;
    for (int i = 0; i < n; i++) {
      cin >> b;
      for (int j = b; j < MAX; j++) {
        c[j] = c[j] | c[j - b];
      }
    }

    int mx = -9999;
    for (int i = 0; i <= a; i++) {
      if (c[i] && is_prime[i]) mx = max(mx, i);
    }
    if (mx == -9999)
      cout << "NA" << endl;
    else
      cout << mx << endl;
  }

  return 0;
}