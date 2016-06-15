#include <assert.h>
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

double const EPS = 1e-8;
typedef vector<double> vec;
typedef vector<vec> mat;

vec gauss_jordan(mat const& A, vec const& b) {
  int n = A.size();
  mat B(n, vec(n + 1));
  rep(i, n) rep(j, n) B[i][j] = A[i][j];
  rep(i, n) B[i][n] = b[i];

  rep(i, n) {
    int pivot = i;
    REP(j, i, n) {
      if (abs(B[j][i]) > abs(B[pivot][i])) {
        pivot = j;
      }
    }
    swap(B[i], B[pivot]);

    if (abs(B[i][i]) < EPS) {
      return vec();
    }

    REP(j, i + 1, n + 1) B[i][j] /= B[i][i];
    rep(j, n) {
      if (i != j) {
        REP(k, i + 1, n + 1) B[j][k] -= B[j][i] * B[i][k];
      }
    }
  }

  vec x(n);
  rep(i, n) x[i] = B[i][n];
  return x;
}

int D;

int main() {
  for (; cin >> D && D;) {
    double v[D + 3];
    rep(i, D + 3) cin >> v[i];
    map<vector<long long>, int> counter;
    rep(i, D + 3) {
      REP(j, i + 1, D + 3) {
        mat A(D + 1, vec(D + 1));
        int p = 0;
        vec b;
        rep(x, D + 3) {
          if (x == i || x == j) {
            continue;
          }
          rep(l, D + 1) { A[p][l] = pow(double(x), D - l); }
          p++;
          b.push_back(v[x]);
        }

        auto s = gauss_jordan(A, b);
        vector<long long> ss(D + 1);
        int sz = s.size();
        rep(ii, sz) { ss[ii] = ceil(s[ii] * 10); }
        auto tt = ss;
        ss.push_back(i);
        tt.push_back(j);
        counter[ss]++;
        counter[tt]++;
      }
    }
    for (auto e : counter) {
      /*
      rep(i, e.first.size()) {
        cout << e.first[i] << endl;
      }
      cout << endl;
      */
      if (e.second >= D + 2) {
        cout << e.first.back() << endl;
        goto exit;
      }
    }
    assert(false);
  exit:;
  }

  return 0;
}