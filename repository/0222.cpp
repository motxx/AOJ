#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000001

bool is_prime[MAX];

void Sieve() {
  fill(is_prime, is_prime + MAX, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i < MAX; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j < MAX; j += i) is_prime[j] = false;
    }
  }
}

int main() {
  Sieve();

  int n;
  while (cin >> n && n) {
    for (int i = n - 8; i >= 0; i--) {
      if (is_prime[i] && is_prime[i + 2] && is_prime[i + 6] &&
          is_prime[i + 8]) {
        cout << i + 8 << endl;
        break;
      }
    }
  }

  return 0;
}