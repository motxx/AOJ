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

#define REP(i, a, b) for (int i = a; i < (int)b; i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) \
  { cout << #a << " = " << a << endl; }
template <class T1, class T2>
inline bool minimize(T1 &a, T2 b) {
  return b < a && (a = b, 1);
}
template <class T1, class T2>
inline bool maximize(T1 &a, T2 b) {
  return a < b && (a = b, 1);
}

using namespace std;

// ﾃ･ﾂ渉づｨﾂ??
// http://d.hatena.ne.jp/kkishi/20090707/1246930309

bool forbid_0[10];
int coef[10];
int ASize;
bool used[10];
int sum;

int dfs(int idx) {
  int ret = 0;
  if (idx == ASize) return sum == 0;

  rep(digit, 10) {
    if (digit == 0 && forbid_0[idx]) continue;
    if (used[digit]) continue;
    used[digit] = 1, sum += coef[idx] * digit;
    ret += dfs(idx + 1);
    used[digit] = 0, sum -= coef[idx] * digit;
  }
  return ret;
}

int main() {
  int N;
  while (cin >> N && N) {
    vector<string> v(N);

    string alphs;
    rep(i, N) {
      cin >> v[i];
      alphs += v[i];
    }

    // ACM, IBM, ICPC => {A,B,C,I,M,P}
    // ﾃｦﾂ鳴?･ﾂｭﾂ療･ﾂ按預lphsﾃ｣ﾂ?ｨﾃ｣ﾂ?療｣ﾂ?ｦﾃｩﾂ??｣ﾂ?ｫﾃ､ﾂｸﾂｦﾃ｣ﾂ?ｹﾃ｣ﾂつ?
    sort(all(alphs));
    alphs.erase(unique(all(alphs)), alphs.end());

    /*
      ﾃ･ﾂ青?ｦﾂ鳴?･ﾂｭﾂ療｣ﾂ?ｮﾃ､ﾂｿﾂづｦﾂ閉ｰﾃ｣ﾂつ津･ﾂ?暗｣ﾂ?ｫﾃｨﾂｨﾂ暗ｧﾂｮﾂ療｣ﾂ?凖｣ﾂつ?
      ACM + IBM = ICPC ﾃ｣ﾂつ暗｣ﾂつ甘｣ﾂ??
      100*A+10*C+M + 100*I+10*B+M = 1000*I+101*C+10*P
      100*A +10*B -91*C -900*I +2*M -10*P = 0
      ﾃ｣ﾂ?禿｣ﾂつ古｣ﾂつ津ｦﾂｺﾂ?｣ﾂ?淌｣ﾂ?凖｣ﾂつ暗｣ﾂ??｣ﾂ?ｪA, B, C, I, M,
      Pﾃ｣ﾂ?ｮﾃ･ﾂ?､ﾃ｣ﾂつ津ｦﾂｱﾂづ｣ﾂつ?｣ﾂつ?
      */

    // alphsﾃ､ﾂｸﾂ甘｣ﾂ?ｮﾃ､ﾂｽﾂ催ｧﾂｽﾂｮﾃ｣ﾂつ津ｧﾂ可ｹﾃ･ﾂｮﾂ堙｣ﾂ?凖｣ﾂつ?
    vector<vector<int>> pos(N);
    rep(i, N) rep(j, v[i].size()) pos[i].push_back(alphs.find(v[i][j]));

    rep(i, 10) coef[i] = 0;

    // ﾃ･ﾂｷﾂｦﾃｨﾂｾﾂｺﾃ｣ﾂつ津ｨﾂｶﾂｳﾃ｣ﾂ??
    rep(i, N - 1) rep(j, pos[i].size()) coef[pos[i][j]] +=
        pow(10, (int)pos[i].size() - 1 - j);

    // ﾃ･ﾂ渉ｳﾃｨﾂｾﾂｺﾃ｣ﾂつ津･ﾂｼﾂ陛｣ﾂ??
    rep(i, pos.back().size()) coef[pos.back()[i]] -=
        pow(10, (int)pos.back().size() - 1 - i);

    // 0ﾃ｣ﾂつ津･ﾂ渉姪｣ﾂつ古｣ﾂ?ｪﾃ｣ﾂ??｣ﾂつ｢ﾃ｣ﾂδｫﾃ｣ﾂδ陛｣ﾂつ｡ﾃ｣ﾂδ凖｣ﾂδε｣ﾂδ暗｣ﾂつ津ｧﾂ可ｹﾃ･ﾂｮﾂ堙｣ﾂ?凖｣ﾂつ?
    rep(i, 10) forbid_0[i] = 0;
    rep(i, N) if (pos[i].size() > 1) forbid_0[pos[i][0]] = 1;

    ASize = alphs.size();

    rep(i, 10) used[i] = 0;
    sum = 0;
    cout << dfs(0) << endl;
  }

  return 0;
}