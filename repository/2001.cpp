#include <algorithm>
#include <iostream>
#include <vector>
//#include <numeric>

using namespace std;

typedef pair<int, int> Pii;

#define MP make_pair
#define F first
#define S second

int main() {
  int n, m, a;
  while (cin >> n >> m >> a, (n | m | a)) {
    vector<pair<int, Pii> > vec(m);
    for (int i = 0; i < m; i++) {
      int h, p, q;
      cin >> h >> p >> q;
      vec[i] = MP(h, Pii(p, q));
    }

    sort(vec.begin(), vec.end());
    vector<int> ans(n + 1);
    // iota(ans.begin(), ans.end(), 0);
    for (int i = 0; i < n + 1; i++) ans[i] = i;

    for (int i = 0; i < m; i++) swap(ans[vec[i].S.F], ans[vec[i].S.S]);

    cout << ans[a] << endl;
  }

  return 0;
}