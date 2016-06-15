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

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

ll N, M, A, B, C, T;

namespace Matrix {
using number_type = long long;
using Vec = vector<number_type>;
using Mat = vector<Vec>;

Mat operator*(Mat& A, Mat& B) {
  Mat C(A.size(), Vec(B[0].size()));
  rep(i, A.size()) rep(k, B.size()) rep(j, B[0].size()) C[i][j] =
      (C[i][j] + A[i][k] * B[k][j]) % M;
  return C;
}

void operator*=(Mat& A, Mat& B) { A = A * B; }

Mat pow(Mat A, ll n) {
  Mat B(A.size(), Vec(A.size()));
  rep(i, A.size()) { B[i][i] = 1; }
  while (n > 0) {
    if (n & 1) {
      B *= A;
    }
    A *= A;
    n >>= 1;
  }
  return std::move(B);
}

Mat operator^(Mat A, ll n) { return std::move(pow(std::move(A), n)); }

Mat make_matrix(number_type a, number_type b, number_type c, number_type d) {
  Mat ret(2, Vec(2));
  ret[0][0] = a, ret[0][1] = b, ret[1][0] = c, ret[1][1] = d;
  return std::move(ret);
}
}

// Matrix::Vec S;
Matrix::Mat S;

int main() {
  for (; cin >> N >> M >> A >> B >> C >> T && (N | M | A | B | C | T);) {
    // !!! Column Vector !!!
    S.clear();
    S.resize(N);
    rep(i, N) S[i].resize(1);
    rep(i, N) cin >> S[i][0];

    Matrix::Mat mat;
    int pos = 0;
    while (pos < N) {
      Matrix::Vec v(N);
      if (pos - 1 >= 0 && pos - 1 < N) {
        v[pos - 1] = A;
      }
      if (pos + 0 >= 0 && pos + 0 < N) {
        v[pos + 0] = B;
      }
      if (pos + 1 >= 0 && pos + 1 < N) {
        v[pos + 1] = C;
      }
      pos++;
      mat.push_back(v);
    }
    assert(mat.size() == N);

    mat = Matrix::pow(mat, T);

    Matrix::Mat res = Matrix::operator*(mat, S);
    /*
    rep(i, mat.size()) {
      rep(j, N) {
        res[j] += mat[i][j] * S[j] % M;
        res[j] %= M;
      }
    }
    */

    rep(i, N) {
      if (i) cout << " ";
      cout << res[i][0] % M;
    }
    cout << endl;
  }
  return 0;
}