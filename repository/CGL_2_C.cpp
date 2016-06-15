#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const double EPS = 1E-10;
typedef vector<double> vec;
typedef vector<vec> mat;

vec gauss_jordan(const mat& A, const vec& b) {
  int n = A.size();
  mat B(n, vec(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      B[i][j] = A[i][j];
    }
  }

  for (int i = 0; i < n; i++) B[i][n] = b[i];

  for (int i = 0; i < n; i++) {
    int pivot = i;
    for (int j = i; j < n; j++) {
      if (fabs(B[j][i]) > fabs(B[pivot][i])) pivot = j;
    }
    swap(B[i], B[pivot]);

    if (fabs(B[i][i]) < EPS) return vec();

    for (int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
    for (int j = 0; j < n; j++) {
      if (i != j) {
        for (int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
      }
    }
  }
  vec x(n);
  for (int i = 0; i < n; i++) x[i] = B[i][n];
  return x;
}

int main() {
  int n;

  double x[4], y[4];

  cin >> n;
  for (int i = 0; i < n; i++) {
    mat A;
    vec a, b;
    for (int j = 0; j < 4; j++) {
      cin >> x[j] >> y[j];
    }

    a.push_back(y[1] - y[0]);
    a.push_back(x[0] - x[1]);
    A.push_back(a);

    b.push_back((y[1] - y[0]) * x[0] - (x[1] - x[0]) * y[0]);

    a.clear();
    a.push_back(y[3] - y[2]);
    a.push_back(x[2] - x[3]);
    A.push_back(a);

    b.push_back((y[3] - y[2]) * x[2] - (x[3] - x[2]) * y[2]);

    vec ans(2);
    ans = gauss_jordan(A, b);

    // if(fabs(ans[0]) < EPS) ans[0] = 0.0;
    // if(fabs(ans[1]) < EPS) ans[0] = 0.0;
    printf("%.10lf %.10lf\n", ans[0], ans[1]);
  }

  return 0;
}