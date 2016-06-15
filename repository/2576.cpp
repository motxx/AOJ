#include <deque>
#include <iostream>
using namespace std;

deque<pair<int, int> > Deq;

int Dfs(int iDx, int markeD, int D) {
  if (iDx == Deq.size()) {
    return markeD;
  }

  int enD = Dfs(iDx + 1, markeD, D);
  if (D >= Deq[iDx].first) {
    enD = max(enD, Dfs(iDx + 1, markeD + Deq[iDx].second, D - Deq[iDx].first));
  }

  return enD;
}

int main() {
  int D;
  cin >> D;
  int x;
  cin >> x;
  string a;
  int p;
  for (int i = 0; i < x; i++) {
    cin >> a >> p;
    if (a == "D") {
      Deq.push_back(make_pair(1, p));
    }
  }

  int y;
  cin >> y;
  string b;
  int q;
  for (int i = 0; i < y; i++) {
    cin >> b >> q;
    if (b == "DD") {
      Deq.push_back(make_pair(2, q));
    }
  }

  cout << Dfs(0, 0, D) << endl;

  return 0;
}