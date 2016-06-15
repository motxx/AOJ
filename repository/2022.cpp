#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline bool cmp(const string &a, const string &b) {
  if (a.size() == b.size()) return a < b;
  return a.size() < b.size();
}

int main() {
  int N;
  while (cin >> N && N) {
    vector<string> vec(N);
    for (int i = 0; i < N; i++) {
      cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    N = vec.size();

    vector<bool> check(N, true);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        if (vec[i].find(vec[j]) != string::npos) check[j] = false;
      }

    vector<string> strs;
    for (int i = 0; i < N; i++) {
      if (check[i]) strs.push_back(vec[i]);
    }

    N = strs.size();
    string next[12][12];
    for (int k = 0; k < N; k++) {
      for (int l = 0; l < N; l++) {
        if (k == l) continue;
        const string &s = strs[k], &t = strs[l];
        int const ssize = s.size(), tsize = t.size();
        next[k][l] = t;
        for (int i = 0; i < ssize; i++) {
          bool ok = true;
          for (int j = 0; j < ssize - i; j++) {
            if (j == tsize) {
              ok = false;
              break;
            }
            if (s[i + j] != t[j]) {
              ok = false;
              break;
            }
          }
          if (ok) {
            next[k][l] = t.substr(ssize - i);
            break;
          }
        }
      }
    }

    string dp[1 << 11][11];

    for (int i = 0; i < N; i++) dp[1 << i][i] = strs[i];

    for (int S = 0; S < (1 << N); S++) {
      for (int i = 0; i < N; i++) {
        if (!(S >> i & 1)) continue;
        if (dp[S][i].empty()) continue;
        for (int j = 0; j < N; j++) {
          if (S >> j & 1) continue;
          if (dp[S | (1 << j)][j].empty())
            dp[S | (1 << j)][j] = dp[S][i] + next[i][j];
          else
            dp[S | (1 << j)][j] =
                min(dp[S | (1 << j)][j], dp[S][i] + next[i][j], cmp);
        }
      }
    }

    string ans = dp[(1 << N) - 1][0];
    for (int i = 0; i < N; i++) {
      ans = min(ans, dp[(1 << N) - 1][i], cmp);
    }
    cout << ans << endl;
  }

  return 0;
}