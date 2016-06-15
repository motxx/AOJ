#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const double EPS = 1E-8;
typedef vector<double> vd;
typedef vector<vd> mat;

// 拡大係数行列で解く
vector<double> GaussJordan(const mat& A, const vd b) {
  int n = A.size();
  mat B(n, vd(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) B[i][j] = A[i][j];
  }
  for (int i = 0; i < n; i++) {
    B[i][n] = b[i];
  }

  for (int i = 0; i < n; i++) {
    int pivot = i;
    for (int j = i; j < n; j++) {
      if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
    }
    swap(B[i], B[pivot]);

    if (abs(B[i][i]) < EPS) return vd();

    for (int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
    for (int j = 0; j < n; j++) {
      if (i != j) {
        for (int k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
      }
    }
  }
  vd x(n);
  for (int i = 0; i < n; i++) x[i] = B[i][n];
  return x;
}

int main() {
  int tcase;
  cin >> tcase;
  while (tcase--) {
    double x[3], y[3];
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    mat A(3, vd(3, 0));
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == 2)
          A[i][j] = 1;
        else
          A[i][j] = (j % 2 ? y[i] : x[i]);
      }
    }

    vd b(3);
    for (int i = 0; i < 3; i++) b[i] = -(x[i] * x[i] + y[i] * y[i]);

    vd v = GaussJordan(A, b);

    double cX = -v[0] / 2, cY = -v[1] / 2;
    double r = sqrt(pow(x[0] - cX, 2) + pow(y[0] - cY, 2));
    printf("%.3f %.3f %.3f\n", cX, cY, r);
  }

  return 0;
}