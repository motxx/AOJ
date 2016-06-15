#include <iostream>
using namespace std;

int p, q, a, n;

int dfs(int nume, int deno, int x, int k) {
  if (p * deno == q * nume) {
    return 1;
  }

  // p/q < nume/deno
  if (p * deno < q * nume) {
    return 0;
  }

  if (k == n) {
    return 0;
  }

  int ret = 0;
  for (int i = x; deno * i <= a; i++) {
    // A/B + 1/C = (AC+B)/BC
    ret += dfs(nume * i + deno, deno * i, i, k + 1);
  }

  return ret;
}

int main() {
  while (cin >> p >> q >> a >> n && (p | q | a | n))
    cout << dfs(0, 1, 1, 0) << endl;

  return 0;
}