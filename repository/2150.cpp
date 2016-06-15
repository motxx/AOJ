#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX (300001)

bool is_prime[MAX + 1];
vector<long long> prime;
int size;

void Sieve() {
  fill(is_prime, is_prime + MAX, true);

  is_prime[0] = is_prime[1] = false;

  for (long long i = 2; i <= MAX; i++) {
    if (is_prime[i]) {
      prime.push_back(i);
      for (long long j = i * i; j <= MAX; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  int n, p;

  Sieve();

  while (cin >> n >> p, !(n == -1 && p == -1)) {
    int st = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
    vector<long long> vec;
    for (int i = st; i <= st + p; i++) {
      for (int j = i; j <= st + p; j++) {
        vec.push_back(prime[i] + prime[j]);
      }
    }
    sort(vec.begin(), vec.end());
    cout << vec[p - 1] << endl;
  }

  return 0;
}