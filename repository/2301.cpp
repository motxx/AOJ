#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int K;
double R, L;
double P, E, T;

#define EPS (1e-5)

typedef long long ll;

double solve(int const kcnt, double ll, double rr, double prob) {
  if (T + E < ll || rr + E < T) return 0.;
  if (abs(ll - T) <= E && abs(rr - T) <= E) return prob;
  // if(prob*pow(max(1.-P, P), K-kcnt)*pow(2., K) < EPS) return 0.;
  // if(prob*pow(max(1.-P, P), K-kcnt) < EPS) return 0.;

  double H = (ll + rr) / 2.;

  if (kcnt == K) {
    if (abs(H - T) <= E) {
      return prob;
    } else {
      return 0.;
    }
  }

  // step 3.
  double ret = 0.;
  if (H <= T) {
    ret += solve(kcnt + 1, H, rr, prob * (1. - P));
    ret += solve(kcnt + 1, ll, H, prob * P);
  } else {
    ret += solve(kcnt + 1, ll, H, prob * (1. - P));
    ret += solve(kcnt + 1, H, rr, prob * P);
  }

  return ret;
}

int main() {
  cin >> K >> L >> R;
  cin >> P >> E >> T;

  printf("%.7f\n", solve(0, L, R, 1.));

  return 0;
}