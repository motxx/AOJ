#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool ok;
vector<int> ans;
vector<int> a;

void rec(int sum, vector<int>& cnt, vector<int>& v) {
  if (sum == 0) {
    ans = v;
    ok = true;
    return;
  }

  for (int i = 1; i <= 13; i++) {
    if (cnt[i] && sum % i == 0) {
      v.push_back(i);
      cnt[i]--;
      rec(sum - i, cnt, v);
      if (ok) return;
      cnt[i]++;
      v.pop_back();
    }
  }
}

int main() {
  int n;

  while (cin >> n && n) {
    vector<int> a(n);
    vector<int> cnt(14, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
      sum += a[i];
    }

    vector<int> v;
    ok = false;
    rec(sum, cnt, v);

    if (ok) {
      reverse(ans.begin(), ans.end());
      int const N = ans.size();
      for (int i = 0; i < N; i++) {
        if (i)
          cout << " " << ans[i];
        else
          cout << ans[i];
      }
      cout << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}