#include <iostream>
using namespace std;

int main() {
  int n;

  while (cin >> n && n) {
    int ans = 0;
    for (int i = 0; i * i <= n; i++) {
      if (i * i > n) break;
      for (int j = i; j * j <= n; j++) {
        if (i * i + j * j > n) break;
        for (int k = j; k * k <= n; k++) {
          if (i * i + j * j + k * k > n) break;
          for (int l = k; l * l <= n; l++) {
            if (i * i + j * j + k * k > n) break;
            if (n == i * i + j * j + k * k + l * l) ans++;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}