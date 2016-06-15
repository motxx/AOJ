#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define F first
#define S second
typedef pair<int, int> Pii;

int main() {
  int m, n;
  while (cin >> m && m) {
    vector<Pii> M;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      M.push_back(Pii(x, y));
    }
    cin >> n;
    set<Pii> st;
    vector<Pii> N;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      N.push_back(Pii(x, y));
      st.insert(Pii(x, y));
    }

    for (int i = 0; i < n; i++) {
      int mvX = N[i].F - M[0].F;
      int mvY = N[i].S - M[0].S;
      bool ok = true;
      for (int j = 1; j < m; j++) {
        ok = ok && st.count(Pii(M[j].F + mvX, M[j].S + mvY));
      }
      if (ok) {
        cout << mvX << " " << mvY << endl;
        goto EXIT;
      }
    }
  EXIT:;
  }
  return 0;
}