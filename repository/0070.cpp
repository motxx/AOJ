#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int memo[11][350];
int N, S;
bool used[11];

int const MAX = 330;

void dfs(int cnt, int sum) {
  if (sum > MAX) return;
  if (cnt > 10) return;

  for (int i = 0; i < 10; i++) {
    if (used[i]) continue;
    used[i] = 1;
    int next = i * cnt;
    memo[cnt][sum + next]++;
    dfs(cnt + 1, sum + next);
    used[i] = 0;
  }
}

int main() {
  fill(used, used + 10, 0);
  dfs(1, 0);
  while (cin >> N >> S) {
    if (S > MAX)
      cout << 0 << endl;
    else
      cout << memo[N][S] << endl;
  }

  return 0;
}