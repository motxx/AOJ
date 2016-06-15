// ﾃｦﾂつｲﾃ｣ﾂ?療｣ﾂ??
#include <assert.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)

deque<char> plus1(deque<char> const& a) {
  if (a == deque<char>{'0'}) {
    return {'1'};
  }

  deque<char> ret;
  ret.push_back('0');
  copy(a.begin(), a.end(), back_inserter(ret));
  ret.back() += 1;
  int N = ret.size();
  int idx = N - 1;
  while (ret[idx] == '9' + 1) {
    ret[idx] = '0';
    ret[--idx] += 1;
  }

  deque<char> ans;
  bool ok = false;
  REP(i, 0, N) {
    if (ok || (ret[i] != '0')) {
      ok = 1;
      ans.push_back(ret[i]);
    }
  }

  return ans;
}

deque<char> zeroclear(deque<char>& s) {
  deque<char> ret;
  bool ok = false;
  rep(i, s.size()) {
    if (ok || s[i] != '0') {
      ok = 1;
      ret.push_back(s[i]);
    }
  }
  if (ret.empty()) {
    ret.push_back('0');
    ;
  }
  return ret;
}
struct comp {
  bool operator()(deque<char> const& a, deque<char> const& b) {
    int asize = a.size(), bsize = b.size();
    if (asize != bsize) {
      return asize < bsize;
    }
    for (int i = 0; i < asize; i++) {
      if (a[i] != b[i]) {
        return a[i] < b[i];
      }
    }
    return 0;
  }
};

int main() {
  int N;
  cin >> N;
  string S;
  rep(i, N) {
    char ch;
    cin >> ch;
    S.push_back(ch);
  }

  set<deque<char>, comp> vs;
  rep(i, N) {
    deque<char> s;
    REP(j, i, N) {
      if (j - i > 7) {
        continue;
      }
      s.push_back(S[j]);
      vs.insert(zeroclear(s));
    }
  }

  //  int cc = 0;
  //  for(auto& s: vs) { if(++cc >= 15) { break; } rep(i, s.size()) { cout <<
  //  s[i]; } cout << endl; }cout << endl;
  //  rep(i, v.size()) {  cout << v[i] << endl; }cout << endl;

  deque<char> curr;
  curr.push_back('0');
  for (auto& s : vs) {
    if (curr != s) {
      rep(i, curr.size()) { cout << curr[i]; }
      cout << endl;
      exit(0);
    }
    curr = plus1(curr);
    //    cout << "---\n";   cout << curr << endl;
  }

  rep(i, curr.size()) { cout << curr[i]; }
  cout << endl;

  return 0;
}