#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { cout << #a << " = " << a << endl; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }

typedef long long ll;
string const invalid = string(1, '0'-10);

struct number {
  string s;
  number() {};
  number(string const& s): s(s) {};
  bool operator < (number const& r) const {
    if (s.size() != r.s.size()) return s.size() < r.s.size();
    return s < r.s;
  }
  bool operator == (const number &x) const {
    return s == x.s;
  }
};
  
ostream& operator << (ostream& ost, number const& r) {
  return ost << r.s;
}

string s;
number dp[55][55];

string nine(string s) {
  const int n = s.size();
  rep(i, n) if(s[i] == '?') s[i] = '9';
  if(n > 1 && s[0] == '0') return invalid;
  return s;
}

#define srange s.begin()+l, s.begin()+r

number solve(int l, int r) {

  auto& ret = dp[l][r];
  if(!ret.s.empty()) return ret;

  ret = invalid;

  bool dcheck = 1;
  REP(i, l, r) dcheck &= isdigit(s[i]) || s[i] == '?';
  if(dcheck) return ret = nine(string(srange));

  if((s[l] == 'L' || s[l] == 'R' || s[l] == '?') &&
     (s[l + 1] == '(' || s[l + 1] == '?') &&
     (s[r - 1] == ')' || s[r - 1] == '?')) {
    REP(i, l + 3, r - 2) {
      if(s[i] != '?' && s[i] != ',') continue;
      auto L = solve(l + 2, i);
      auto R = solve(i + 1, r - 1);
      if(L == invalid) continue;
      if(R == invalid) continue;
      if(s[l] == 'L' || s[l] == '?') ret = max(ret, L);
      if(s[l] == 'R' || s[l] == '?') ret = max(ret, R);
    }
  }

  return ret;
}

int main() {
  cin >> s;
  auto r = solve(0, s.size());
  if(r == invalid) cout << "invalid\n";
  else cout << r << endl;
  return 0;
}