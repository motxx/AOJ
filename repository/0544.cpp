#include <iostream>

using namespace std;

int main(void) {
  int masu[1001] = {0};
  int m, n;
  int s, now = 1;
  int count = 0;
  int update = 0;

  while (1) {
    update = 0;
    now = 1;
    for (int i = 0; i < 1001; i++) masu[i] = 0;

    cin >> n >> m;
    if (n == 0 && m == 0) break;

    // cout << "n: "<< n << " m: " << m << endl;
    for (int i = 1; i <= n; i++) {
      // cout << "i: " << i << endl;
      cin >> masu[i];
    }

    int j;
    for (j = 1; j <= m; j++) {
      cin >> s;
      now += s;
      now += masu[now];
      if (now < 0) now = 0;
      if (now > 1000) now = 1000;

      if (n <= now && update == 0) {
        update = 1;
        count = j;
      }
      // cout << "j: " << j << endl;
    }

    cout << count << endl;
  }

  return 0;
}