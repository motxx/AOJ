#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class SumOf2DArray {
 private:
  vector<vector<int> > a;
  vector<vector<ll> > S;
  int N_, M_;

  void precalc() {
    for (int i = 0; i < N_; i++)
      for (int j = 0; j < M_; j++) S[i + 1][j + 1] = S[i + 1][j] + a[i][j];

    for (int i = 0; i < N_; i++)
      for (int j = 0; j < M_; j++) S[i + 1][j + 1] += S[i][j + 1];
  }

 public:
  SumOf2DArray(const vector<vector<int> >& a) {
    N_ = a.size();
    M_ = a[0].size();
    this->a = a;
    this->S.assign(N_ + 1, vector<ll>(M_ + 1, 0));
    precalc();
  }

  /*
    a[i][j] -> a[k][l] の和を求める。
    戻り値：long long
   */
  ll sum(int i, int j, int k, int l) {
    return S[k + 1][l + 1] - S[k + 1][j] - S[i][l + 1] + S[i][j];
  }

  /*
    長方形区間の最大の和を求める。O(N^4)
   */
  ll maxSum() {
    ll res = LLONG_MIN;
    for (int i = 0; i < N_; i++)
      for (int j = 0; j < M_; j++)
        for (int k = i; k < N_; k++)
          for (int l = j; l < M_; l++) res = max(res, sum(i, j, k, l));
    return res;
  }
};

int main() {
  int N;
  cin >> N;
  vector<vector<int> > a;
  a.resize(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) cin >> a[i][j];

  SumOf2DArray s(a);
  cout << s.maxSum() << endl;

  return 0;
}