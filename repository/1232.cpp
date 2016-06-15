#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (long long)b; i++)
#define rep(i, n) REP(i, 0, n)

int const MAX = 100000;
typedef long long ll;
bool isnp[MAX + 1];
vector<int> primes;

int main() {
  for (int i = 2; (ll)i * i <= MAX; i++) {
    if (isnp[i]) continue;
    for (int j = i * i; j <= MAX; j += i) {
      isnp[j] = 1;
    }
  }

  for (int i = 2; i <= MAX; i++)
    if (!isnp[i]) {
      primes.push_back(i);
    }
  /*
  rep(i, 10) { cerr << primes[i] << endl; }
  */
  int m, a, b;
  while (cin >> m >> a >> b && (m | a | b)) {
    ll mx = 0;
    int ansp = -1, ansq = -1;
    REP(q, 1, m) {
      if (isnp[q]) continue;
      double pu = (double)m / q;
      // cerr << "pu: " << pu << endl;
      int k =
          upper_bound(primes.begin(), primes.end(), pu) - primes.begin() - 1;
      REP(pi, max(k - 10, 0), k + 10) {
        int p = primes[pi];
        // cerr << p << ", " << q << endl;
        if (p > q) continue;
        if (a * q > b * p) continue;
        if (mx < p * q && p * q <= m) {
          mx = p * q, ansp = p, ansq = q;
        }
      }
    }
    cout << ansp << " " << ansq << endl;
  }

  return 0;
}