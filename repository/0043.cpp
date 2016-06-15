#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

int tmp[10];
int counter[10];

bool dfs(bool two) {
  bool ok = 1;
  REP(i, 1, 10) if (counter[i]) { ok = 0; }
  if (ok) return true;

  REP(i, 1, 10) {
    if (i < 8 && counter[i] && counter[i + 1] && counter[i + 2]) {
      counter[i]--;
      counter[i + 1]--;
      counter[i + 2]--;
      if (dfs(two)) return true;
      counter[i]++;
      counter[i + 1]++;
      counter[i + 2]++;
    }
    if (!two && counter[i] > 1) {
      counter[i] -= 2;
      if (dfs(true)) return true;
      counter[i] += 2;
    }
    if (counter[i] > 2) {
      counter[i] -= 3;
      if (dfs(two)) return true;
      counter[i] += 3;
    }
  }
  return false;
}

int main() {
  string str;
  while (cin >> str) {
    rep(i, 10) tmp[i] = 0;
    rep(i, 13) tmp[str[i] - '0']++;

    vector<int> ans;
    REP(insert, 1, 10) {
      rep(i, 10) counter[i] = tmp[i];
      counter[insert]++;
      if (counter[insert] > 4) continue;
      if (dfs(false)) {
        ans.push_back(insert);
      }
    }

    if (ans.empty()) {
      cout << 0;
    }

    rep(i, ans.size()) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }

  return 0;
}