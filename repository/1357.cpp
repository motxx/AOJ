#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define minimize(a, x) a = std::min(a, x)
#define maximize(a, x) a = std::max(a, x)

typedef long long ll;
ll const Inf = 1LL << 60;

int N;

int main() {
  cin >> N;
  deque<long double> radius(N);
  rep(i, N) { cin >> radius[i]; }

  if (N == 1) {
    printf("%.10Lf\n", radius[0] * 2.0);
    exit(0);
  }

  vector<long double> positions;
  vector<int> lasts;
  //  vector<long double> starts;
  long double start = 0.0;
  rep(i, N) {
    long double x = 0.0;
    rep(j, i) {
      long double px = positions[j];
      long double s = radius[i] + radius[j];
      s *= s;
      long double h = abs(radius[i] - radius[j]);
      h *= h;
      long double w = sqrt(s - h);
      if (x < px + w) {
        x = px + w;
      }
    }
    positions.push_back(x);
    lasts.push_back(i);
    minimize(start, x - radius[i]);
    //    starts.push_back(min(-radius[0], x - radius[i]));
  }

  //  rep(i, radius.size()) { cout << radius[i]; }; cout << endl << radius[0] <<
  //  endl;
  //  cout << "-----------------\n";rep(i, positions.size()) { printf("%.10Lf
  //  %.5Lf\n", positions[i], radius[lasts[i]]); } cout <<
  //  "-----------------\n";

  long double ret = 0.0;
  rep(i, positions.size()) {
    maximize(ret, positions[i] - start + radius[lasts[i]]);
  }
  printf("%.10Lf\n", ret);

  return 0;
}