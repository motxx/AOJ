#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Rank {
 public:
  Rank() {}
  Rank(int s, int ti, int te) : s(s), ti(ti), te(te) {}
  int s, ti, te;
};
bool comp(const Rank &r1, const Rank &r2) {
  if (r1.s == r2.s && r1.s == 0) return r1.te < r2.te;
  return r1.s != r2.s ? r1.s < r2.s
                      : (r1.ti != r2.ti ? r1.ti < r2.ti : r1.te < r2.te);
}

int main() {
  int m, t, p, j;
  int M, T, P, R;
  vector<Rank> rank;
  while (cin >> M >> T >> P >> R && M + T + P + R) {
    rank.clear();
    int penal[55][12];
    bool solved[55][12];

    fill(penal[0], penal[52], 0);
    fill(solved[0], solved[52], 0);

    for (int ii = 0; ii < R; ii++) {
      cin >> m >> t >> p >> j;
      p--;
      t--;
      if (j != 0)
        penal[t][p] += 20;
      else
        penal[t][p] += m, solved[t][p] = true;
    }
    for (int i = 0; i < T; i++) {
      int sum = 0;
      for (int j = 0; j < P; j++) {
        if (solved[i][j]) sum += penal[i][j];
      }
      int ssum = 0;
      for (int j = 0; j < P; j++) {
        ssum += solved[i][j];
      }
      rank.push_back(Rank(-ssum, sum, -i - 1));
    }
    sort(rank.begin(), rank.end(), comp);

    bool flag = 0;
    for (int i = 0; i < rank.size(); i++) {
      if (flag && rank[i - 1].s == rank[i].s && rank[i - 1].ti == rank[i].ti)
        cout << "=";
      else if (flag)
        cout << ",";
      cout << -rank[i].te;
      flag = 1;
    }
    cout << endl;
  }

  return 0;
}