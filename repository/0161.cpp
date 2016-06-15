#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> Pii;
int main() {
  int n;
  while (cin >> n && n) {
    vector<Pii> vec(n);
    for (int ii = 0; ii < n; ii++) {
      int S, m, s;
      cin >> S;
      int t = 0;
      for (int i = 0; i < 4; i++) {
        cin >> m >> s;
        t += s + m * 60;
      }
      vec[ii] = Pii(t, S);
    }
    sort(vec.begin(), vec.end());
    cout << vec[0].second << endl
         << vec[1].second << endl
         << vec[vec.size() - 2].second << endl;
  }
  return 0;
}