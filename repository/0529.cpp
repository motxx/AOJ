#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define pb push_back

int main() {
  int n, m;

  while (cin >> n >> m && (n | m)) {
    vector<int> data;
    vector<int> Q;

    n++;
    data.pb(0);
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      data.pb(a);
    }

    for (int i = 0; i < n; i++) {
      Q.pb(data[i]);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        Q.pb(data[i] + data[j]);
      }
    }

    sort(Q.begin(), Q.end());

    // for(int i=0; i<T; i++) cout << Q[i] << endl;

    int ans = 0;

    for (int i = 0; i < Q.size(); i++) {
      int M = m - Q[i];
      if (M < 0) break;

      int lb = 0, ub = Q.size();

      while (ub - lb > 1) {
        int mid = (lb + ub) / 2;

        if (Q[mid] <= M) {
          lb = mid;
        } else {
          ub = mid;
        }
      }
      ans = max(ans, Q[i] + Q[lb]);
    }

    cout << ans << endl;
  }

  return 0;
}