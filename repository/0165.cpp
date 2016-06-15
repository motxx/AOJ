#include <bits/stdc++.h>

using namespace std;

int const MP = 999983;

bool is_prime[MP + 1];
int sum_prime[MP + 1];

void Sieve() {
  fill(is_prime, is_prime + MP + 1, true);
  is_prime[0] = is_prime[1] = false;

  for (int i = 2; (long long)i * i <= MP; i++) {
    if (is_prime[i]) {
      for (long long j = i * i; j <= MP; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 0; i < MP + 1; i++) {
    sum_prime[i + 1] += sum_prime[i] + is_prime[i + 1];
  }
}

int main() {
  Sieve();

  int N;
  while (cin >> N && N) {
    int X = 0;
    for (int i = 0; i < N; i++) {
      int p, m;
      cin >> p >> m;
      int L = max(p - m, 1), R = min(p + m, MP);
      int cnt = sum_prime[R] - sum_prime[L - 1] - 1;
      X += cnt;
    }
    cout << X << endl;
  }

  return 0;
}