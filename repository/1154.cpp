#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAX 300001
bool is_MSPrime[MAX + 1];

void makeMSPrime() {
  fill(is_MSPrime, is_MSPrime + MAX, true);
  is_MSPrime[0] = is_MSPrime[1] = false;
  for (int i = 0; i <= MAX; i++) {
    if ((i % 7 == 1 || i % 7 == 6) && is_MSPrime[i]) {
      for (int j = i + i; j <= MAX; j += i) {
        // for(int j=i*i ... ) ...
        is_MSPrime[j] = false;
      }
    }
  }
}

int main() {
  int n;

  makeMSPrime();

  while (cin >> n && n != 1) {
    cout << n << ":";

    for (int i = 1; i <= n; i++) {
      if ((i % 7 == 1 || i % 7 == 6) && is_MSPrime[i] && n % i == 0)
        cout << " " << i;
    }
    cout << endl;
  }

  return 0;
}