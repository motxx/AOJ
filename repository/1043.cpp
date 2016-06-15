#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Rank {
 public:
  int I, U, A, P;
  Rank();
  Rank(int I, int U, int A, int P) : I(I), U(U), A(A), P(P) {}
};

bool comp(const Rank &r1, const Rank &r2) {
  if (r1.A != r2.A) return r1.A > r2.A;
  if (r1.P != r2.P) return r1.P < r2.P;
  return r1.I < r2.I;
}

int main() {
  int n;
  int ii, uu, aa, pp;
  while (cin >> n && n) {
    vector<Rank> vec;
    for (int i = 0; i < n; i++) {
      cin >> ii >> uu >> aa >> pp;
      vec.push_back(Rank(ii, uu, aa, pp));
    }
    sort(vec.begin(), vec.end(), comp);

    vector<Rank> res;
    vector<int> UCnt(1001, 0);

    for (int i = 0; i < vec.size(); i++) {
      if (res.size() < 10 && UCnt[vec[i].U] < 3) {
        res.push_back(vec[i]);
      } else if (res.size() < 20 && UCnt[vec[i].U] < 2)
        res.push_back(vec[i]);
      else if (res.size() < 26 && UCnt[vec[i].U] == 0)
        res.push_back(vec[i]);
      UCnt[vec[i].U]++;
    }

    for (int i = 0; i < res.size(); i++) {
      cout << res[i].I << endl;
    }
  }

  return 0;
}