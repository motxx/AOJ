#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)

inline string toStr(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

int N, K;
vector<string> v;
vector<bool> used;
set<string> st;
void rec(int cnt, string s) {
  if (cnt == K) {
    st.insert(s);
    return;
  }

  rep(i, N) {
    if (used[i]) continue;
    used[i] = 1;
    rec(cnt + 1, s + v[i]);
    used[i] = 0;
  }
}

int main() {
  while (cin >> N >> K && N) {
    st.clear();
    v.clear();
    v.resize(N);
    used.clear();
    used.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    rec(0, "");
    cout << st.size() << endl;
  }

  return 0;
}