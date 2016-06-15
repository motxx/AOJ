#include <iostream>
using namespace std;

int rec(int n, int k, int s) {
  if (k == 0) {
    if (s == 0)
      return 1;
    else
      return 0;
  }

  if (s < 0) return 0;

  int res = 0;
  for (int i = n; i >= 1; i--) {
    res += rec(i - 1, k - 1, s - i);
  }

  return res;
}

int main() {
  int n, k, s;
  while (cin >> n >> k >> s, (n | k | s)) {
    cout << rec(n, k, s) << endl;
  }

  return 0;
}