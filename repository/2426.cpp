#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
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
#define watch(a) \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1e9 + 10;

int xs[5001], ys[5001];
int sum[5100][5100];

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> X = {-inf, inf}, Y = {-inf, inf};
  rep(i, N) {
    scanf("%d%d", &xs[i], &ys[i]);
    X.push_back(xs[i]);
    Y.push_back(ys[i]);
  }

  sort(X.begin(), X.end());
  X.erase(unique(all(X)), X.end());
  sort(Y.begin(), Y.end());
  Y.erase(unique(all(Y)), Y.end());

  rep(i, N) {
    sum[upper_bound(all(Y), ys[i]) - Y.begin()]
       [upper_bound(all(X), xs[i]) - X.begin()]++;
  }

  rep(i, Y.size() + 10) rep(j, X.size() + 10) {
    if (i && j) sum[i][j] -= sum[i - 1][j - 1];
    if (i) sum[i][j] += sum[i - 1][j];
    if (j) sum[i][j] += sum[i][j - 1];
  }

  rep(i, M) {
    int rx1, ry1, rx2, ry2;
    scanf("%d%d%d%d", &rx1, &ry1, &rx2, &ry2);
    int x1 = lower_bound(all(X), rx1) - X.begin();
    int y1 = lower_bound(all(Y), ry1) - Y.begin();
    int x2 = upper_bound(all(X), rx2) - X.begin();
    int y2 = upper_bound(all(Y), ry2) - Y.begin();
    printf("%d\n", sum[y2][x2] - sum[y2][x1] - sum[y1][x2] + sum[y1][x1]);
  }

  return 0;
}