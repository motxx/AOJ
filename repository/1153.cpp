#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int taro[100], hanako[100];
int n, m;

int main() {
  int n, m;

  while (cin >> n >> m, (n | m)) {
    for (int i = 0; i < n; i++) cin >> taro[i];
    for (int i = 0; i < m; i++) cin >> hanako[i];

    int const staro = accumulate(taro, taro + n, 0);
    int const shanako = accumulate(hanako, hanako + m, 0);

    int mn = 1000;
    int ans1 = -1, ans2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int const a = -taro[i] + hanako[j];
        if (staro + a == shanako - a && mn > taro[i] + hanako[j]) {
          ans1 = taro[i], ans2 = hanako[j];
          mn = taro[i] + hanako[j];
        }
      }
    }
    if (ans1 == -1)
      cout << "-1" << endl;
    else
      cout << ans1 << " " << ans2 << endl;
  }

  return 0;
}