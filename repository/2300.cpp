#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<double> L, a, b;

inline double SQ(double x) { return x * x; }

double solve(vector<int> &v, const int idx, const double sum, const int cnt) {
  if (cnt == M) {
    return sum;
  }

  if (idx == N) {
    return 0.;
  }

  double ret;
  {
    double add = 0.;
    for (int i = 0; i < v.size(); i++) {
      add += SQ(L[idx] - L[v[i]]) + SQ(a[idx] - a[v[i]]) + SQ(b[idx] - b[v[i]]);
    }
    v.push_back(idx);
    ret = solve(v, idx + 1, sum + add, cnt + 1);
    v.pop_back();
  }
  { ret = max(ret, solve(v, idx + 1, sum, cnt)); }

  return ret;
}

int main() {
  cin >> N >> M;
  L.resize(N);
  a.resize(N);
  b.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> L[i] >> a[i] >> b[i];
  }

  vector<int> v;
  printf("%.7f\n", solve(v, 0, 0., 0));

  return 0;
}