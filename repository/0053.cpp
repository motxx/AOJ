#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000

vector<int> prime;
bool is_prime[MAX + 1];

void Sieve() {
  for (int i = 0; i <= MAX; i++) {
    is_prime[i] = true;
  }

  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i <= MAX; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (int j = 2 * i; j <= MAX; j += i) is_prime[j] = false;
    }
  }
}

int main() {
  Sieve();

  int n;
  while (cin >> n && n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += prime[i];
    }
    cout << sum << endl;
  }

  return 0;
}