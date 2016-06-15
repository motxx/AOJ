#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct before_main {
  before_main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
  }
} before_main;

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1& a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1& a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = (1e9) * 2;
int n;

int to_int(deque<int>& C) {
  int ret = 0;
  reverse(all(C));
  rep(i, C.size()) {
    ret *= 10;
    ret += C[i];
  }
  reverse(all(C));
  return ret;
}

int dfs(string& A, string& B, int K, int i, int borrow, deque<int>& C) {
  /*
ﾃ｣ﾂ??｣ﾂ??.1. Aiﾃ｢ﾂ按鍛orrowiﾃ｢ﾂ可･Bi
ﾃ｣ﾂ?ｪﾃ｣ﾂつ嘉｣ﾂ?ｰﾃ｣ﾂ??Ci=Aiﾃ｢ﾂ按鍛orrowiﾃ｢ﾂ按達i
ﾃｯﾂｼﾂ?borrowi+1=0ﾃ｣ﾂ?ｨﾃ｣ﾂ?凖｣ﾂつ凝｣ﾂ??
ﾃ｣ﾂ??｣ﾂ??.2. Aiﾃ｢ﾂ按鍛orrowi<Bi
ﾃ｣ﾂ?ｪﾃ｣ﾂつ嘉｣ﾂ?ｰﾃ｣ﾂ??Ci=Aiﾃ｢ﾂ按鍛orrowi+10ﾃ｢ﾂ按達i
ﾃｯﾂｼﾂ?borrowi+1=1ﾃ｣ﾂ?ｨﾃ｣ﾂ?凖｣ﾂつ凝｣ﾂ??
  */
  if (n == i) {
    return to_int(C);
  }

  int ret = -inf;

  if (A[i] - borrow >= B[i]) {
    C.push_back(A[i] - borrow - B[i]);
    maximize(ret, dfs(A, B, K, i + 1, 0, C));
    C.pop_back();
  } else {
    C.push_back(A[i] - borrow + 10 - B[i]);
    maximize(ret, dfs(A, B, K, i + 1, 1, C));
    if (K) maximize(ret, dfs(A, B, K - 1, i + 1, 0, C));
    C.pop_back();
  }
  return ret;
}

int main() {
  int A, B, K;
  cin >> A >> B >> K;
  string a = to_string(A), b = to_string(B);
  reverse(all(a)), reverse(all(b));
  n = max(a.size(), b.size());
  REP(i, a.size(), n) a.push_back('0');
  REP(i, b.size(), n) b.push_back('0');
  deque<int> C;
  cout << dfs(a, b, K, 0, 0, C) << endl;

  return 0;
}