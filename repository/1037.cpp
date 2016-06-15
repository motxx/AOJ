#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

int N, M;
vector<int> vs;
string S;
string::const_iterator iter;

map<int, int> merge(map<int, int>& a, map<int, int>& b) {
  map<int, int> ret;
  rep(i, 0b10000) rep(j, 0b10000) {
    ret[i & j] += a[i] * b[j];
    ret[i | j] += a[i] * b[j];
    ret[i ^ j] += a[i] * b[j];
  }
  return ret;
}

map<int, int> dfs() {
  if (*iter == '(') {
    iter++;
    auto l = dfs();
    iter++;
    auto r = dfs();
    iter++;
    return merge(l, r);
  } else {
    int a = *iter - '0';
    a--;
    iter++;
    return {{vs[a], 1}};
  }
}

int main() {
  while (1) {
    getline(cin, S);
    if (S == "END") break;
    N = S.size();
    cin >> M;
    vs.clear();
    rep(i, M) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      vs.push_back(a * 8 + b * 4 + c * 2 + d);
    }

    iter = S.begin();
    auto s = dfs();

    cout << s[0b1111] << endl;
    cin.ignore();
  }

  return 0;
}