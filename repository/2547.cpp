#include <assert.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void main_();
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  main_();
  return 0;
}

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

typedef long long ll;
int const inf = 1 << 29;

void main_() {
  int N;
  cin >> N;
  stack<int> st;
  int ans = 0;
  rep(i, N) {
    int a;
    cin >> a;
    if (!st.empty() && st.top() == a) {
      continue;
    }  // ﾃｩﾂｫﾂ佚｣ﾂ?陛｣ﾂ?古ｩﾂ?｣ﾃｧﾂｶﾂ堙｣ﾂ?凖｣ﾂつ凝｣ﾂ?ｮﾃ｣ﾂ?ｧﾃ｣ﾂつｹﾃ｣ﾂδｫﾃ｣ﾂδｼ
    if (st.empty() || st.top() < a) {
      st.push(a);
    }
    while (!st.empty() && st.top() > a) {
      st.pop();
      ans++;
    }
    if (st.empty() || st.top() != a) {
      st.push(a);
    }
  }

  cout << ans + st.size() << endl;
}