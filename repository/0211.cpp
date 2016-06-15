#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

inline ll gcd(ll a, ll b) { return b > 0 ? gcd(b, a % b) : a; }

inline ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
  int N;
  while (cin >> N && N) {
    vector<ll> vd(N), vv(N);
    rep(i, N) {
      cin >> vd[i] >> vv[i];
      int const GCD = gcd(vd[i], vv[i]);
      vd[i] /= GCD, vv[i] /= GCD;
    }

    ll D = vd[0], V = vv[0];
    REP(i, 1, N) {
      D = lcm(D, vd[i]);
      V = gcd(V, vv[i]);
    }
    // cout << D << " " << V << endl;

    rep(i, N) cout << D * vv[i] / V / vd[i] << endl;
  }

  return 0;
}