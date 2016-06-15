#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int N;
int x[24], y[24], r[24], c[24];
int on[24];

#define SQ(x) ((x) * (x))
inline bool isIntersect(int i, int j) {
  return SQ(x[j] - x[i]) + SQ(y[j] - y[i]) < SQ(r[j] + r[i]);
}

inline bool isValid(int i, int S) {
  for (int j = 0; j < i; j++) {
    if ((on[i] >> j & 1) && !(S >> j & 1)) return false;
  }
  return true;
}

char memo[1 << 24];
char dfs(int S, const int sum) {
  char& ret = memo[S];
  if (ret != -1) return ret;
  ret = sum;
  for (int i = 0; i < N; i++) {
    if (S >> i & 1) continue;
    if (!isValid(i, S)) continue;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (c[i] != c[j]) continue;
      if (S >> j & 1) continue;
      if (!isValid(j, S)) continue;
      ret = max(ret, dfs(S + (1 << i) + (1 << j), sum + 2));
    }
  }

  return ret;
}

int main() {
  while (cin >> N && N) {
    for (int i = 0; i < N; i++) {
      cin >> x[i] >> y[i] >> r[i] >> c[i];
      on[i] = 0;
      for (int j = 0; j < i; j++) {
        if (isIntersect(i, j)) on[i] += 1 << j;
      }
    }
    memset(memo, -1, sizeof memo);
    cout << (int)dfs(0, 0) << endl;
  }

  return 0;
}