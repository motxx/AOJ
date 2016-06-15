#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  int N;
  cin >> N;

  double x[N], y[N];
  rep(i, N) { cin >> x[i] >> y[i]; }

  double sum = 0;
  rep(i, N) { sum += (x[i] - x[(i + 1) % N]) * (y[i] + y[(i + 1) % N]); }

  printf("%.1f\n", sum / 2.);

  return 0;
}