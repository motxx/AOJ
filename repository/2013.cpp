#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  for (int n; cin >> n, n;) {
    int h, m, s;
    int data[86401] = {};
    for (int i = 0; i < n; i++) {
      scanf("%d:%d:%d", &h, &m, &s);
      data[h * 3600 + m * 60 + s]++;
      scanf("%d:%d:%d", &h, &m, &s);
      data[h * 3600 + m * 60 + s]--;
    }

    int res = 0;
    for (int i = 0; i <= 86400; i++) {
      data[i + 1] += data[i];
      res = max(res, data[i]);
    }

    cout << res << endl;
  }

  return 0;
}