#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int l[10], r[10], s[10];
int n, x, m;

vector<int> ans;
int mx;

bool dfs(int num, vector<int>& lion) {
  if (num == n) {
    for (int i = 0; i < m; i++) {
      int sum = 0;
      for (int j = l[i]; j <= r[i]; j++) sum += lion[j];
      if (sum != s[i]) {
        return false;
      }
    }

    int all = 0;
    for (int i = 0; i < n; i++) {
      all += lion[i];
    }

    if (mx < all) {
      mx = all;
      ans = lion;
    }

    return true;
  } else {
    bool ok = false;
    for (int i = 0; i <= x; i++) {
      lion[num] = i;
      ok |= dfs(num + 1, lion);
    }
    return ok;
  }
}

int main() {
  cin >> n >> x >> m;

  mx = -1;

  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> s[i];
    l[i]--;
    r[i]--;
  }

  mx = -1;
  vector<int> lion(n);

  bool valid = dfs(0, lion);

  if (valid) {
    for (int i = 0; i < n; i++) {
      if (i)
        cout << " " << ans[i];
      else
        cout << ans[i];
    }
    cout << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}