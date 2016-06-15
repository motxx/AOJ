#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int memo[1200][1200];

int center[1200];
int center2[1200][1200];

typedef pair<int, int> Pii;
map<int, Pii> mp1;
map<Pii, Pii> mp2;

int N;
string line;

bool is_palindrome(int L, int R) {
  if (L >= R) return 1;

  if (memo[L][R] != -1) {
    return memo[L][R];
  }

  int SIZE = R - L;

  if (line[L] == line[R - 1]) {
    memo[L][R] = is_palindrome(L + 1, R - 1);

    if (memo[L][R] == 1) {
      if (R - L > 2) {
        if (SIZE % 2 == 0) {
          int l = (L + R) / 2, r = (L + R) / 2 + 1;
          if (center2[l][r] < R - L) {
            mp2[Pii(l, r)] = Pii(L, R);
            center2[l][r] = R - L;
          }
        } else {
          int m = (L + R) / 2;
          if (center[m] < R - L) {
            mp1[m] = Pii(L, R);
            center[m] = R - L;
          }
        }
      }
      return 1;
    } else if (memo[L][R] == 0)
      return 0;
    else
      assert(false);
  }
  memo[L][R] = 0;
  return 0;
}

void kirei() {
  string ret;
  int const N = line.size();
  rep(i, N) {
    if (isalpha(line[i])) {
      ret += toupper(line[i]);
    }
  }
  line = ret;
}

bool cmp(string const& a, string const& b) { return a.size() < b.size(); }

vector<string> contains_remove(vector<string>& vec) {
  vector<bool> retbool(vec.size());
  vector<string> ret;
  sort(vec.begin(), vec.end(), cmp);

  rep(i, vec.size()) {
    int ISize = vec[i].size();
    REP(j, i + 1, vec.size()) {
      int JSize = vec[j].size();
      if (ISize % 2 != JSize % 2) continue;
      if (ISize % 2 == 0) {
        if (vec[i] == string(vec[j].begin() + (JSize / 2 - ISize / 2),
                             vec[j].begin() + (JSize / 2 + ISize / 2))) {
          retbool[i] = 1;
        }
      } else {
        if (vec[i] == string(vec[j].begin() + (JSize / 2 - ISize / 2),
                             vec[j].begin() + (JSize / 2 + ISize / 2 + 1))) {
          retbool[i] = 1;
        }
      }
    }
  }

  for (int i = 0; i < (int)vec.size(); i++) {
    if (!retbool[i]) {
      ret.push_back(vec[i]);
    }
  }

  return ret;
}

int main() {
  while (getline(cin, line)) {
    rep(i, 1200) {
      rep(j, 1200) {
        memo[i][j] = -1;
        center2[i][j] = -1;
      }
      center[i] = -1;
    }
    mp1.clear(), mp2.clear();

    kirei();
    N = line.size();

    rep(i, N) REP(j, i + 1, N + 1) { memo[i][j] = is_palindrome(i, j); }

    vector<string> vec;
    {
      map<int, Pii>::iterator it = mp1.begin();
      for (; it != mp1.end(); it++) {
        int L = it->second.first;
        int R = it->second.second;
        vec.push_back(string(line.begin() + L, line.begin() + R));
      }
    }
    {
      map<Pii, Pii>::iterator it = mp2.begin();
      for (; it != mp2.end(); it++) {
        int L = it->second.first;
        int R = it->second.second;
        vec.push_back(string(line.begin() + L, line.begin() + R));
      }
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    vec = contains_remove(vec);

    for (int i = 0; i < (int)vec.size(); i++) {
      if (i) cout << " ";
      cout << vec[i];
    }
    cout << endl;
  }

  return 0;
}